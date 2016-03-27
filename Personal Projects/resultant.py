# AUTHOR: Mansur
# DATE: 2016-01-21
# PURPOSE: Gets the resultant vector

import math

class Vector:
    def __init__(self, i, j, k, magnitude):
        self.i = i
        self.j = j
        self.k = k
        self.magnitude = magnitude

        self.reset()
        
    def reset(self):
        self.scalarMultiple = self.magnitude / math.sqrt(
        self.i**2+self.j**2+self.k**2)

        self.fx = self.i * self.scalarMultiple
        self.fy = self.j * self.scalarMultiple
        self.fz = self.k * self.scalarMultiple

        self.alpha = math.acos(self.fx/self.magnitude)
        self.beta = math.acos(self.fy/self.magnitude)
        self.gamma = math.acos(self.fz/self.magnitude)
    
    def getDirection(self):
        return [self.i, self.j, self.k]

    def getVector(self):
        return [self.fx, self.fy, self.fz]

    def resetReference(self, i, j, k):
        self.i -= i
        self.j -= j
        self.k -= k
        self.reset()

def main():
    vectors = []
    vectorResultant = [0, 0, 0]

    rX = 0
    rY = 0
    rZ = 0

    n_vectors = int(input("Enter number of vectors: "))

    for i in range(n_vectors):
        _i = float(input("\nEnter i for vector " + str(i+1) +": "))
        _j = float(input("Enter j for vector " + str(i+1) +": "))
        _k = float(input("Enter k for vector " + str(i+1) +": "))
        _m = float(input("Enter magnitude for vector " + str(i+1) + ": "))

        vectors.append(Vector(_i, _j, _k, _m))

    
        

    for i in range(len(vectors)):
        currentVector = vectors[i].getVector()

        rX += currentVector[0]
        rY += currentVector[1]
        rZ += currentVector[2]

    vectorResultant[0] = rX
    vectorResultant[1] = rY
    vectorResultant[2] = rZ

    vectorRMagnitude = math.sqrt(vectorResultant[0]**2 +
                                 vectorResultant[1]**2 +
                                 vectorResultant[2]**2)

    rAlpha = math.acos(vectorResultant[0] / vectorRMagnitude) * 57.3
    rBeta = math.acos(vectorResultant[1] / vectorRMagnitude) * 57.3
    rGamma = math.acos(vectorResultant[2] / vectorRMagnitude) * 57.3

    print("RESULTANT VECTOR:", vectorResultant)
    print("RESULTANT MAGNITUDE:", vectorRMagnitude)
    print("ALPHA:", rAlpha)
    print("BETA:", rBeta)
    print("GAMMA:", rGamma)

main()
