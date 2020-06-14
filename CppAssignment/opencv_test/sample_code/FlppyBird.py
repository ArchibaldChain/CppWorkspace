import cv2
import random


class FlppyBird:
    def __init__(self, frame):
        self.frame = frame
        self.Tubes = []
        self.frame_size = frame.shape
        self.upperBound = int(frame.shape[0]/4)
        self.lowerBound = int(frame.shape[0]/4*3)

        self.tub1 = cv2.imread("pictures/tubeup.png")
        self.tub2 = cv2.imread("pictures/tubedown.png")
        self.tubewide = 20  # self.tub1.shape[0]
        self.gate_size = 1/6 * self.frame_size[0]

    def setTubes(self):
        if self.Tubes == []:
            g = self.generateGate()
            self.Tubes.append(g)
            return self.frame

        print len(self.Tubes)
        for t in self.Tubes:
            print self.frame.shape
            print t.getGateCordinate()
            self.drawTube(t)
            t.moveLeft()

        # when the first one from the right enter into the frame
        if self.frame_size[0] - self.Tubes[-1].x2 > 10*self.tubewide:
            g = self.generateGate()
            self.Tubes.append(g)

        if self.Tubes[0].x2 <= 0:
            self.Tubes.remove(0)

        return self.frame

    def drawTube(self, t):
        print t.getUpTube(), t.getLowTube(self.frame_size[1])
        a, b = t.getUpTube()
        cv2.rectangle(self.frame, a, b, (255, 2, 2), 2)
        a, b = t.getLowTube(self.frame_size[1])
        cv2.rectangle(self.frame, a, b, (255, 2, 2), 2)

    def generateGate(self):
        x = self.generateNum()
        y = self.frame_size[0]
        return Gate(x, y, x+self.gate_size, y+self.tubewide)

    def generateNum(self):
        return random.randint(self.upperBound, (self.lowerBound - self.gate_size))


class Gate:
    def __init__(self, x1, y1, x2, y2):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2

    def getGateCordinate(self):
        return (self.x1, self.y1), (self.x2, self.y2)

    def getUpTube(self):
        return (0, self.y1), (self.x1, self.y2)

    def getLowTube(self, m):
        return (self.x1, self.y1), (m, self.y2)

    def moveLeft(self):
        steplen = 2
        self.x1 += steplen
        self.x2 += steplen
        self.y1 += steplen
        self.y2 += steplen
