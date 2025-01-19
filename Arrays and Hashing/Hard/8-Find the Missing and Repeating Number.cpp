Prob Link:""

Optimal approach:-
    Steps:
        let's understand this by an example- let's take an array given -[4,3,6,2,1,1]
            now , i will calculate the sum of array , and sum till 1 to n by formula (n*(n+1))/2;
            Substract Sarr-Sn this will give -4;
                (4+3+6+2+1+1) - (1+2+3+4+5+6) = 1-5 = -4//this is x-y(where x is repeating no. and y is missing no.)
            now , i will calculate the sum of squares of all nos. in array , and sum of squares by formula from 1 to n (n*(n+1)*(2n+1))/6;
            Substract Ssq.arr.-Sn2 =-24
                (4^2+3^2+....)-(1^2+2^2+3^2+4^2+....) = -24 //this is x^2-y^2
            x+y = (x^2-y^2)/(x-y)
            x = ((x-y)+(x+y))/2; //find y also from eqns. and return x,y 
            Dhyaan rahe sab kuch long long me type cast kar lena pehle 

    CODE:-
        vector<int> findMissingRepeatingNumbers(vector<int> a) {
        long long n = a.size(); // size of the array

        // Find Sn and S2n:
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        // Calculate S and S2:
        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += a[i];
            S2 += (long long)a[i] * (long long)a[i];
        }

        //S-Sn = X-Y:
        long long val1 = S - SN;

        // S2-S2n = X^2-Y^2:
        long long val2 = S2 - S2N;

        //Find X+Y = (X^2-Y^2)/(X-Y):
        val2 = val2 / val1;

        //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
        // Here, X-Y = val1 and X+Y = val2:
        long long x = (val1 + val2) / 2;
        long long y = x - val1;

        return {(int)x, (int)y};
        }


One more optimal solution , but you can stick to upper one for interviews 
More OPTIMAL Solution: Using XOR->see in striver's article ->"https://takeuforward.org/data-structure/find-the-repeating-and-missing-numbers/"

