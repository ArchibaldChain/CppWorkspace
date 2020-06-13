//
// Created by jyh on 2020/4/22.
//

#include <bits/stdc++.h>
using namespace std;
int evaluate(const char* s, int k) {

    stringstream input(s);
    string word;
    map<string, int> kv;
    while (getline(input, word, ' ')) {
        if((word == " ") || word =="") break;
        auto iter = kv.find(word);
        if (iter == kv.end()) {
            kv[word] = 1;
        }
        else {
            kv[word] += 1;
        }
    }

    // 获取词频最高的单词
    string maxstr = "";
    int maxval = 0;
    for (auto& item:kv) {
        if (item.second > maxval) {
            maxstr = item.first;
            maxval = item.second;
        }
    } // 返回
    cout << maxstr <<" :"<< maxval<<endl;
    return maxval >= k ? 1 : 0;
}
int main() {
    cout << evaluate("jiu dang shi yi chang meng xing le hen jiu hai shi hen gan dong", 2) << endl;
    cout << evaluate("dan huang de chang qun peng song de tou fa", 4) << endl;
    cout << evaluate("ke shi ban pei zai han shui li you duo le ji ge dan  wei nao hai zhong\
    de xuan lv ru ci shu xi ai guo ni zai wo xin li zhi neng qing qing tan xi wu shu dong  \
    ren yin fu zai wo sheng ming ai guo ni shi qua \
    ni wo cai zhi dao yao zhen xi meng li duo shao ci rang shi guang dao tui bu \
    xu yao bao bei ceng jing ba suo you mei hao gan yuan zai ni shen shang hao \
    fei xiang zhan shi xie xia kui jia jiao chu quan bu chou ma huan jue qiang \
    di zhong fu zhao deng dai zhao ni de hui da bu ting di chong shua gu ling \
    de zhong shi jian du song kua sheng huo na yao yong ji meng li de kong jian \
    du bei ni gong xia pin cou zhao zhi li de ji yi dian xiang qu ni huai li \
    mian bi bi xian rang shi guang xi xi nian shui wei zhao shui de mi mi yan \
    jiu dang shi yi chang meng xing le hen jiu huan shi hen gan dong huan shi \
    hen xiang bei ni bao hu wo xin li de can tong xi huan wo hen xin ku qi shi \
    wo du qing chu fang xin zhe shi jie hen da dan wo ji de ni de ding zhu ni \
    lai guo you zou ni de jian ding huo fou wo da ying guo ni hui ting hua bu \
    hui liu zai yuan di zhu shou shun zhao lu zou dao xin de ru kou zuo xin de \
    zhu shou ru guo huan yao shuo gao bie de hua na qing ni yi ding zhu kou nao \
    hai zhong de xuan lv ru ci shu xi ai guo ni zai wo xin li zhi neng qing \
    qing tan xi", 14) << endl;

    return 0;
}