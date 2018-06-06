#include<iostream>
#include<utility>
using namespace std;

#define GRID_FULL make_pair(9,9)

pair<int, int> unassigned(int a[9][9]){
  for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
      if(a[i][j]==0){
        return make_pair(i,j);
      }
  return GRID_FULL;
}

bool is_safe_in_row(int a[9][9], int row, int val){
  for(int j=0;j<9;j++)
    if(a[row][j]==val)
      return false;
  return true;
}

bool is_safe_in_col(int a[9][9],int col,int val){
  for(int i=0;i<9;i++)
    if(a[i][col]==val)
      return false;
  return true;
}

bool is_safe_in_box(int a[9][9],int row,int col,int val){
  for(int i=row-row%3;i<row-row%3+3;i++)
    for(int j=col-col%3;j<col-col%3+3;j++)
      if(a[i][j]==val)
        return false;
  return true;
}

bool is_safe(int a[9][9],int row,int col, int val){
  return is_safe_in_row(a,row,val) && is_safe_in_col(a,col,val) && is_safe_in_box(a,row,col,val);
}

bool solve_sudoku(int a[9][9]){
  pair<int,int> row_col = unassigned(a);
  int row = row_col.first;
  int col = row_col.second;
  if(GRID_FULL==row_col)
    return true;
  for(int i=1;i<=9;i++){
    if(is_safe(a,row,col,i)){
      a[row][col] = i;
      if(solve_sudoku(a))
        return true;
      a[row][col] = 0;
    }
  }
  return false;
}

int main(){
  int a[9][9];
  cout<<"Enter a valid sudoku puzzle to be solved\n";
  for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
      cin>>a[i][j];
  if(solve_sudoku(a))
		for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        cout<<a[i][j]<<" ";
      }
      cout<<endl;
    }
	else
		cout << "No solution exists for the given Sudoku" << endl << endl;
    return 0;
}