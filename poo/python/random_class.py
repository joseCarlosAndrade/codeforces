import datetime

class Random:
    def __init__(self, seed = None):
        self.p = 2147483648
        self.m = 843314861
        self.a = 453816693
        if seed == None:
            self.xi = self.unix_time_millis() %self.p
        else:
            self.xi = seed
            

    def getRand(self):
        self.xi = (self.a + self.m * self.xi) % self.p
        d = float(self.xi)
        return d/self.p

    def getIntRand(self, maximo):
        d = self.getRand() * maximo
        return int(d)
    
    def unix_time_millis(self):
        dt = datetime.datetime.utcnow()
        epoch = datetime.datetime.utcfromtimestamp(0)
        x = int((dt - epoch).total_seconds() * 1e6)

        return x
    
if __name__ == "__main__":
    r = Random(1)
    for i in range(100):
        print(r.getIntRand(i), end=' ')
    print()

    r = Random(100)
    for i in range(100):
        print(r.getIntRand(i), end=' ')
    
            
    
