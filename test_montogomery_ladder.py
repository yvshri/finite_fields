def main():
    a = int(raw_input())
    c = int(raw_input())
    f1 = a
    f2 = a*a
    for i in bin(c)[3::]:
        print i
        if(int(i)==0):
            print 1
            f2 = f1*f2
            f1 = f1*f1
        else:
            print 2
            f1 = f1*f2
            f2 = f2*f2
        print f1
        print f2

if __name__== "__main__":
    main()
