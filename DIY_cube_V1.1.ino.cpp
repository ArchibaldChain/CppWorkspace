#include <Keypad.h> //控制按位键的库
#define HC138_Y0 3
#define HC138_Y1 4
#define HC138_Y2 5    //74HC138寄存器的三个输入脚
#define TM1818_SDI 9  //data pin
#define TM1818_CLK 10 //clock pin
#define TM1818_LE A3  //latch pin
#define TM1818_OE 8   //open or close OUTs

typedef struct POINT
{
    int x; //xyz为此点坐标
    int y;
    int z;
    int node;    //按5之后node++；按0之后node--；
    char direct; //方向
} point;

typedef struct LIGHT //储存要亮点的坐标
{
    uint8_t x[512]; //点最多为512个
    uint8_t y[512];
    uint8_t z[512];
} light;

point dot;  //点的指针
light ldot; //初始化亮点d
uint8_t afterChange[512];

/*
 * keypad的按键初始化
 */
const byte ROWS = 4; //设置行数
const byte COLS = 4; //设置列数

//按键对应的符号
char hexaKeys[ROWS][COLS] = {
    {'1', '4', '7', '*'},
    {'2', '5', '8', '0'},
    {'3', '6', '9', '#'},
    {'A', 'B', 'C', 'D'}};

// byte rowPins[ROWS] = {5,4,3,2}; // 按钮矩阵对应接入Arduino的端口
// byte colPins[COLS] = {9,8,7,6}; // 按钮矩阵对应接入Arduino的端口
byte rowPins[ROWS] = {36, 34, 32, 30}; // 按钮矩阵对应接入Arduino的端口
byte colPins[COLS] = {44, 42, 40, 38}; // 按钮矩阵对应接入Arduino的端口

// 初始化一个keypad类的对象
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

/***************
 * 点初始化
 * 在（1，1，1）处
 */
void Init_Point()
{
    dot.x = 0;
    dot.y = 0;
    dot.z = 0;
    dot.node = 0;
    dot.direct = '9';

    ldot.x[0] = ldot.y[0] = ldot.z[0] = 0;
}

/*
 * 按'5'保存此时xyz坐标
 */
void Save_5()
{
    dot.node++;
    ldot.x[dot.node] = dot.x;
    ldot.y[dot.node] = dot.y;
    ldot.z[dot.node] = dot.z;
}

/*
 * 按其他按键后save实时点
 */
void Save_other()
{
    ldot.x[0] = dot.x;
    ldot.y[0] = dot.y;
    ldot.z[0] = dot.z;
}

/*
 * 按'0'删除储存的相应坐标
 */
void Delete()
{
    //int index =0;
    for (int i = 1; i <= dot.node; i++)
    {
        if (dot.x == ldot.x[i] & dot.y == ldot.y[i] & dot.z == ldot.z[i])
        {
            //通过遍历数组内后面内容把要删除的点位置删除
            for (int index = i; index < dot.node; index++)
            { //把后面遍历到前面
                ldot.x[index] = ldot.x[index + 1];
                ldot.y[index] = ldot.y[index + 1];
                ldot.z[index] = ldot.z[index + 1];
            }
            dot.node--; //数组长度减1
            i--;        //重新检测移后那一位
        }
    }
}

//控制哪个面发光

void scanSurface(byte m) //displayOutput调用的函数
{
    switch (m)
    {
    case 0:
        digitalWrite(HC138_Y0, LOW);
        digitalWrite(HC138_Y1, LOW);
        digitalWrite(HC138_Y2, LOW);
        break;
    case 4:
        digitalWrite(HC138_Y0, LOW);
        digitalWrite(HC138_Y1, LOW);
        digitalWrite(HC138_Y2, HIGH);
        break;
    case 2:
        digitalWrite(HC138_Y0, LOW);
        digitalWrite(HC138_Y1, HIGH);
        digitalWrite(HC138_Y2, LOW);
        break;
    case 6:
        digitalWrite(HC138_Y0, LOW);
        digitalWrite(HC138_Y1, HIGH);
        digitalWrite(HC138_Y2, HIGH);
        break;
    case 1:
        digitalWrite(HC138_Y0, HIGH);
        digitalWrite(HC138_Y1, LOW);
        digitalWrite(HC138_Y2, LOW);
        break;
    case 5:
        digitalWrite(HC138_Y0, HIGH);
        digitalWrite(HC138_Y1, LOW);
        digitalWrite(HC138_Y2, HIGH);
        break;
    case 3:
        digitalWrite(HC138_Y0, HIGH);
        digitalWrite(HC138_Y1, HIGH);
        digitalWrite(HC138_Y2, LOW);
        break;
    case 7:
        digitalWrite(HC138_Y0, HIGH);
        digitalWrite(HC138_Y1, HIGH);
        digitalWrite(HC138_Y2, HIGH);
        break;
    default:
        break;
    }
}

//改变坐标格式并在led发光
void ChangeAndShow()
{
    int index; //存在数组内的位置
    //将xyz轴转为必要格式
    for (int i = 0; i < 512; i++)
    {
        afterChange[i] = 0;
    }

    for (int i = 0; i <= dot.node; i++)
    {
        if ((ldot.x[i] % 2) == 0)
        {
            int index = 8 * ldot.x[i] + ldot.y[i] + 64 * ldot.z[i]; // 将xyz轴换为512的二进制数，给光立方读取
            afterChange[index] = 1;
        }
        else
        {
            int index = 7 + 8 * ldot.x[i] - ldot.y[i] + 64 * ldot.z[i]; // 将xyz轴换为512的二进制数，给光立方读取
            afterChange[index] = 1;
        }
    }

    //把512数组转为64数组
    uint8_t output[64] = {0};
    int i, j, k;
    for (i = 0; i < 512; i += 8)
    {
        for (j = i; j < i + 8; j++)
        {
            output[i / 8] += (afterChange[j] << (i - j + 7));
        }
    }

    // 发光
    uint8_t displayTemp;
    for (int i = 0; i < 64; i += 8) //每一层亮
    {
        digitalWrite(TM1818_OE, HIGH); //关闭OUT输出

        digitalWrite(TM1818_LE, HIGH);  //关闭锁存，data could be put in 1818_SDI
        delayMicroseconds(1);           //给芯片反应的时间 如果删掉没有影响可以删掉
        for (int j = i; j < i + 8; j++) //控制这一层64个灯的的8个8位二进制元素
        {
            displayTemp = output[j]; //将所有screen赋值给displayTemp

            for (int k = 0; k < 8; k++) //将这8个二进制数输入到SDI
            {
                digitalWrite(TM1818_CLK, LOW); //时钟上升时移位数据
                delayMicroseconds(1);
                digitalWrite(TM1818_SDI, displayTemp & 0x01);
                displayTemp >>= 1;
                delayMicroseconds(1);
                digitalWrite(TM1818_CLK, HIGH); //一个时钟周期结束
                delayMicroseconds(1);
            }
        }
        digitalWrite(TM1818_LE, LOW); //打开锁存，SDI不允许被修改
        delayMicroseconds(1);
        scanSurface(i / 8);           //这一面亮其他面关闭
        digitalWrite(TM1818_OE, LOW); //打开OUT输出，亮灯
        delayMicroseconds(500);       //可改变光立方亮度
    }
}

void show()
{
    //把512数组转为64数组
    uint8_t output[64] = {0};
    int i, j, k;
    for (i = 0; i < 512; i += 8)
    {
        for (j = i; j < i + 8; j++)
        {
            output[i / 8] += (afterChange[j] << (i - j + 7));
        }
    }

    // 发光
    uint8_t displayTemp;
    for (int i = 0; i < 64; i += 8) //每一层亮
    {
        digitalWrite(TM1818_OE, HIGH); //关闭OUT输出

        digitalWrite(TM1818_LE, HIGH);  //关闭锁存，data could be put in 1818_SDI
        delayMicroseconds(1);           //给芯片反应的时间 如果删掉没有影响可以删掉
        for (int j = i; j < i + 8; j++) //控制这一层64个灯的的8个8位二进制元素
        {
            displayTemp = output[j];    //将所有screen赋值给displayTemp
            for (int k = 0; k < 8; k++) //将这8个二进制数输入到SDI
            {
                digitalWrite(TM1818_CLK, LOW); //时钟上升时移位数据
                delayMicroseconds(1);
                digitalWrite(TM1818_SDI, displayTemp & 0x01);
                displayTemp >>= 1;
                delayMicroseconds(1);
                digitalWrite(TM1818_CLK, HIGH); //一个时钟周期结束
                delayMicroseconds(1);
            }
        }
        digitalWrite(TM1818_LE, LOW); //打开锁存，SDI不允许被修改
        delayMicroseconds(1);
        scanSurface(i / 8);           //这一面亮其他面关闭
        digitalWrite(TM1818_OE, LOW); //打开OUT输出，亮灯
        delayMicroseconds(500);
    }
}

void Clear(int delayTime)
{          // switch 到'C'后全部复位
    int i; //控制面的点
    int j; //控制面

    for (i = 0; i < 64; i++)
    { //0
        afterChange[i] = 1;
    }
    show();
    //delay(delayTime);//延迟时间可通过调试更改；
    for (i = 64; i < 128; i++)
    { //0 和 1
        afterChange[i] = 1;
    }
    show();
    //delay(delayTime);
    for (i = 128; i < 192; i++)
    { //0 1 2
        afterChange[i] = 1;
    }
    show();
    //delay(delayTime);
    for (i = 192; i < 256; i++)
    { //0！ 1 2 3
        afterChange[i] = 1;
        afterChange[i - 192] = 0;
    }
    show();
    //delay(delayTime);
    for (i = 256; i < 320; i++)
    { // 1！ 2 3 4
        afterChange[i] = 1;
        afterChange[i - 192] = 0;
    }
    show();
    //delay(delayTime);
    for (i = 320; i < 384; i++)
    { // 2！ 3 4 5
        afterChange[i] = 1;
        afterChange[i - 192] = 0;
    }
    show();
    //delay(delayTime);
    for (i = 384; i < 448; i++)
    { // 3！4 5 6
        afterChange[i] = 1;
        afterChange[i - 192] = 0;
    }
    show();
    //delay(delayTime);
    for (i = 448; i < 512; i++)
    { // 4！5 6 7
        afterChange[i] = 1;
        afterChange[i - 192] = 0;
    }
    show();
    //delay(delayTime);
    for (i = 512; i < 576; i++)
    { // 5！6 7
        afterChange[i - 192] = 0;
    }
    show();
    //delay(delayTime);
    for (i = 576; i < 640; i++)
    { // 6！7
        afterChange[i - 192] = 0;
    }
    show();
    //delay(delayTime);
    for (i = 640; i < 704; i++)
    { // 7!
        afterChange[i - 192] = 0;
    }
    show();
}

//假如输出坐标为负数，把它正常输出
void change(int &a)
{
    if (a < 0)
    {
        a = (a % 8) + 8;
    }
    a = a % 8;
}

void setup()
{
    //设置芯片为output
    pinMode(HC138_Y0, OUTPUT);
    pinMode(HC138_Y1, OUTPUT);
    pinMode(HC138_Y2, OUTPUT);
    pinMode(TM1818_CLK, OUTPUT);
    pinMode(TM1818_LE, OUTPUT);
    pinMode(TM1818_OE, OUTPUT);
    pinMode(TM1818_SDI, OUTPUT);

    Serial.begin(9600);
    Init_Point();
    ChangeAndShow(); //显示初始化的点
}

void loop()
{
    char customKey = customKeypad.getKey();

    dot.direct = '9';
    if (customKey)
    {
        dot.direct = customKey;
    }

    switch (dot.direct)
    {
    case '1':
        dot.y += 1;
        change(dot.y);
        Save_other();
        break;
    case '2':
        dot.z += 1;
        change(dot.z);
        Save_other();
        break;
    case '3':
        dot.y -= 1;
        change(dot.y);
        Save_other();
        break;
    case '5':
        Save_5();
        break;
    case '4':
        dot.x -= 1;
        change(dot.x);
        Save_other();
        break;
    case '6':
        dot.x += 1;
        change(dot.x);
        Save_other();
        break;
    case '8':
        dot.z -= 1;
        change(dot.z);
        Save_other();
        break;
    case '0':
        Delete();
        Save_other();
        break;
    case 'C':
        Clear(300);
        Init_Point();
        break; // 300表示延迟0.3秒
    default:
        break;
    }
    ChangeAndShow(); //输出并显示
}
