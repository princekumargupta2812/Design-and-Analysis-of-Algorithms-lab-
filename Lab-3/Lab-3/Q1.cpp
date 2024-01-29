// Assumption: Both the matrices are square matrices of the same order, n.
// Recurrence: T(n) = 8T(n/2) + O(n^2), thus O(n^3) time complexity using master's theorem
// Auxiliary space: O(n ^ 2)
#include <bits/stdc++.h>
using namespace std;

void add(const vector<vector<long long>>& A, const vector<vector<long long>>& B, vector<vector<long long>>& C, int split_index){
    for (auto i = 0; i < split_index; i++)
        for (auto j = 0; j < split_index; j++)
            C[i][j] = A[i][j] + B[i][j];
}

vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B){
    int n = A.size();
    vector<long long> result_matrix_row(n);
    vector<vector<long long>> result_matrix(n, result_matrix_row);

    if (n == 1){
        result_matrix[0][0] = A[0][0] * B[0][0];
    }
    else{
        int split_index = n / 2;

        vector<long long> row(split_index, 0);
        vector<vector<long long>> res_top_left(split_index, row);
        vector<vector<long long>> res_top_right(split_index, row);
        vector<vector<long long>> res_bottom_left(split_index, row);
        vector<vector<long long>> res_bottom_right(split_index, row);

        vector<vector<long long>> a00(split_index, row);
        vector<vector<long long>> a01(split_index, row);
        vector<vector<long long>> a10(split_index, row);
        vector<vector<long long>> a11(split_index, row);
        vector<vector<long long>> b00(split_index, row);
        vector<vector<long long>> b01(split_index, row);
        vector<vector<long long>> b10(split_index, row);
        vector<vector<long long>> b11(split_index, row);

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++)
            {
                a00[i][j] = A[i][j];
                a01[i][j] = A[i][j + split_index];
                a10[i][j] = A[split_index + i][j];
                a11[i][j] = A[i + split_index][j + split_index];
                b00[i][j] = B[i][j];
                b01[i][j] = B[i][j + split_index];
                b10[i][j] = B[split_index + i][j];
                b11[i][j] = B[i + split_index][j + split_index];
            }

        add(multiply(a00, b00), multiply(a01, b10), res_top_left, split_index);
        add(multiply(a00, b01), multiply(a01, b11), res_top_right, split_index);
        add(multiply(a10, b00), multiply(a11, b10), res_bottom_left, split_index);
        add(multiply(a10, b01), multiply(a11, b11), res_bottom_right, split_index);

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++)
            {
                result_matrix[i][j] = res_top_left[i][j];
                result_matrix[i][j + split_index] = res_top_right[i][j];
                result_matrix[split_index + i][j] = res_bottom_left[i][j];
                result_matrix[i + split_index] [j + split_index] = res_bottom_right[i][j];
            }

        res_top_left.clear();
        res_top_right.clear();
        res_bottom_left.clear();
        res_bottom_right.clear();
        a00.clear();
        a01.clear();
        a10.clear();
        a11.clear();
        b00.clear();
        b01.clear();
        b10.clear();
        b11.clear();
    }
    return result_matrix;
}

int main(){
    cout<<"ENTER THE SIZE OF MATRIX"<<endl;
    int n;
    cin>>n;
    cout<<"ENTER THE ELEMENTS OF FIRST MATRIX"<<endl;
    vector<vector<long long>> A(n, vector<long long>(n)), B(n, vector<long long>(n));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin>>A[i][j];
        }
    }
    cout<<"ENTER THE ELEMENTS OF SECOND MATRIX"<<endl;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cin>>B[i][j];
        }
    }
    // function call
    vector<vector<long long>> result_matrix(multiply(A, B));
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            cout<<result_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

