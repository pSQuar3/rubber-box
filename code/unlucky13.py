MOD = 1e9 + 9
M2 = 1e10
F = [[10,1],[-1,0]]
A = [[10,1],[-1,0]]
n = 0
def multiply(P,B):
    w = (((P[0][0]%M2)*(B[0][0]%M2))%M2 + ((P[0][1]%M2)*(B[1][0]%M2))%M2);
    x = (((P[0][0]%M2)*(B[0][1]%M2))%M2 + ((P[0][1]%M2)*(B[1][1]%M2))%M2);
    y = (((P[1][0]%M2)*(B[0][0]%M2))%M2 + ((P[1][1]%M2)*(B[1][0]%M2))%M2);
    z = (((P[1][0]%M2)*(B[0][1]%M2))%M2 + ((P[1][1]%M2)*(B[1][1]%M2))%M2);
    A[0][0] = w;
    A[0][1] = x;
    A[1][0] = y;
    A[1][1] = z;

def power(i):
    if i > 1:
        power(i/2)
        multiply(A,A)
        if i%2 == 1:
            multiply(A,F)

def calci(i):
    if(i <= 1):
        return i;
    F[0][0] = 10;
    F[0][1] = 1;
    F[1][0] = -1;
    F[1][1] = 0;
    A[0][0] = 10;
    A[0][1] = 1;
    A[1][0] = -1;
    A[1][1] = 0;
    power(i-1);
    return A[0][0]%MOD


t = int(input())
while(t != 0):
    n = int(input())
    print(calci(n),"\n")
    t = t-1
