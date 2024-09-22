#include <bits/stdc++.h>
using namespace std;

// Function to print the grid
void print(float arr[][10], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[j][i] << ' ';
        }
        cout << '\n';
    }
}

// Function to perform one iteration of the Laplace equation
void laplace(float arr[][10], float result[][10], int rows, int cols) {
    // Initialize result array to zero
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = arr[i][j];
        }
    }
    // Perform the Laplace update
    for (int i = 1; i < rows - 1; ++i) {
        for (int j = 1; j < cols - 1; ++j) {
            result[i][j] = 0.25 * (arr[i-1][j] + arr[i+1][j] + arr[i][j-1] + arr[i][j+1]);
        }
    }
}

int main() {
    const int ROWS = 10;
    const int COLS = 10;
    float u[ROWS][COLS] = {0};
    float u_new[ROWS][COLS] = {0};
    
    int m,n;
    cout<<"ënter the value of row ad column\n";
    cin>>m>>n;
    cout<<"enter the boundary condition\n";
    for(int i=0;i<m;i++){
        cout<<"ënter the value of u["<<i<<"][0]= ";
        cin>>u[i][0];
    }
    for(int i=1;i<n;i++){
          cout<<"ënter the value of u[0]["<<i<<"]= ";
        cin>>u[0][i];
    }
    for(int i=1;i<n;i++){
          cout<<"ënter the value of u["<<i<<"][3]= ";
        cin>>u[i][3];
    }
       for(int i=1;i<n;i++){
          cout<<"ënter the value of u[3]["<<i<<"]= ";
        cin>>u[3][i];
    }



      u[1][1]=0.25*(u[0][0]+u[0][2]+u[2][0]+0);
      u[2][1]=0.25*(u[2][0]+0+u[1][3]+u[1][1]);
      u[1][2]=0.25*(u[1][1]+0+u[0][2]+u[1][3]);
      u[2][2]=0.25*(u[2][3]+u[1][2]+u[2][1]+u[3][2]);

    // Print initial grid
    print(u,4,4);

    // Perform Laplace update
    laplace(u, u_new, 4, 4);

    // Print updated grid
    cout << "\n grid:\n";
    print(u_new, 4, 4);

    return 0;
}