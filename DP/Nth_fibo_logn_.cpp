//  log(N)  Matrix Exponentiation
 
int MOD = 1e9 + 7;

// function to multiply two 2x2 Matrices
void multiply(vector<vector<long long>>& A,vector<vector<long long>>& B){
    // Matrix to store the result
    vector<vector<long long> > C(2, vector<long long>(2));

    // Matrix Multiply
    C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;

      // Copy the result back to the first matrix
    A[0][0] = C[0][0];
    A[0][1] = C[0][1];
    A[1][0] = C[1][0];
    A[1][1] = C[1][1]; }

// Function to find (Matrix M ^ expo)
vector<vector<long long>> power(vector<vector<long long>> M, int expo){
    // Initialize result with identity matrix
    vector<vector<long long> > ans = { { 1, 0 }, { 0, 1 } };

    // Fast Exponentiation
    while (expo) {
        if (expo & 1)
            multiply(ans, M);
        multiply(M, M);
        expo >>= 1;
    }

    return ans; }

// function to find the nth fibonacci number
int nthFibonacci(int n){
    // base case
    if (n == 0 || n == 1)
        return 1;

    vector<vector<long long> > M = { { 1, 1 }, { 1, 0 } };
    
    // Matrix F = {{f(0), 0}, {f(1), 0}}, where f(0) and
    // f(1) are first two terms of fibonacci sequence
    vector<vector<long long> > F = { { 1, 0 }, { 0, 0 } };

    // Multiply matrix M (n - 1) times
    vector<vector<long long> > res = power(M, n - 1);

    // Multiply Resultant with Matrix F
    multiply(res, F);

    return res[0][0] % MOD;}

int main(){
    int n = 3;

    // Print nth fibonacci number
    cout << nthFibonacci(n) << endl;
}
