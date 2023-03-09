#include <bits/stdc++.h>
using namespace std;
#define M 20
#define N 20
const int modulo = 1e9 + 7;
struct test1
{
    int row;
    int col;
    ////A will stores coefficients of all the variables
    vector <std::vector<float> > A;
    //B will stores constants of constraints
    vector<float> B;
    //C will stores the coefficients of the objective function
    vector<float> C;
    float maximum;
    bool check;
    void Simplex(vector <vector<float> > matrix,vector<float> b ,vector<float> c);
    bool simplexAlgorithmCalculataion();
    bool checkoptimize();
    void doPivot(int pivotRow, int pivotColumn);
    void print();
    int findPivotColumn();
    int findPivotRow(int pivotColumn);
    void CalculateSimplex();
};
void test1::Simplex(std::vector <std::vector<float> > matrix,std::vector<float> b ,std::vector<float> c)
{
            row = matrix.size();
            col= matrix[0].size();
            A.resize( row , vector<float>( col , 0 ) );
            B.resize(b.size());
            C.resize(c.size());
            for(int i= 0;i<row;i++){             //pass A[][] values to the matrix
                for(int j= 0; j< col;j++ ){
                    A[i][j] = matrix[i][j];
                }
            }
            for(int i=0; i< c.size() ;i++ ){      //pass c[] values to the C vector
                C[i] = c[i] ;
            }
            for(int i=0; i< b.size();i++ ){      //pass b[] values to the B vector
                B[i] = b[i];
            }
}
bool test1::simplexAlgorithmCalculataion()
{
    //this funtion to check the table is optimal or not ,if optimal no need to process further
            if(checkoptimize()==true){
			    return true;
            }
            //i will find the column which has the pivot and the least coefficient of the objective function(C array).
            int pivotColumn = findPivotColumn();
            if(check == true){
			    return true;
            }
            //i will find the row with the pivot value, the least value item's row in the B array
            int pivotRow = findPivotRow(pivotColumn);
            //form the next table according to the pivot value
            doPivot(pivotRow,pivotColumn);
            return false;
}
bool test1::checkoptimize()
{
     //if the table has further negative constraints,then it is not optimal
            bool isOptimal = false;
            int count = 0;
            //check if the coefficients of the objective function are negative
            for(int i=0; i<C.size();i++){
                float value = C[i];
                if(value >= 0){
                    count++;
                }
            }
            //if all the constraints are positive now,the table is optimal
            if(count == C.size()){
                isOptimal = true;
                print();
            }
            return isOptimal;
}
void test1::doPivot(int pivotRow, int pivotColumn)
{
            float pivetValue = A[pivotRow][pivotColumn];//gets the pivot value
            float pivotRowVals[col];//the column with the pivot
            float pivotColVals[row];//the row with the pivot
            float rowNew[col];//the row after processing the pivot value
            maximum = maximum - (C[pivotColumn]*(B[pivotRow]/pivetValue));  //set the maximum 
             //get the row that has the pivot value
             for(int i=0;i<col;i++){
                pivotRowVals[i] = A[pivotRow][i];
             }
             //get the column that has the pivot value
             for(int j=0;j<row;j++){
                pivotColVals[j] = A[j][pivotColumn];
            }
            //set the row values that has the pivot value divided by the pivot value and put into new row
             for(int k=0;k<col;k++){
                rowNew[k] = pivotRowVals[k]/pivetValue;
             }
            B[pivotRow] = B[pivotRow]/pivetValue;
             //process the other coefficients in the A array by subtracting
             for(int m=0;m<row;m++){
                if(m !=pivotRow){
                    for(int p=0;p<col;p++){
                        float multiplyValue = pivotColVals[m];
                        A[m][p] = A[m][p] - (multiplyValue*rowNew[p]);
                    }

                }
             }
            //process the values of the B array
            for(int i=0;i<B.size();i++){
                if(i != pivotRow){
                        float multiplyValue = pivotColVals[i];
                        B[i] = B[i] - (multiplyValue*B[pivotRow]);

                }
            }
                //the least coefficient of the constraints of the objective function
                float multiplyValue = C[pivotColumn];
                //process the C array
                 for(int i=0;i<C.size();i++){
                    C[i] = C[i] - (multiplyValue*rowNew[i]);

                }
             //replacing the pivot row in the new calculated A array
             for(int i=0;i<col;i++){
                A[pivotRow][i] = rowNew[i];
             }
}
void test1::print()
{
       for(int i=0; i<row;i++)
       {
                for(int j=0;j<col;j++)
                {
                    cout<<A[i][j] <<" ";
                }
                cout<<""<<endl;
        }
        cout<<""<<endl;
}
//find the least coefficients of constraints in the objective functions position
int test1::findPivotColumn()
{
    //C will stores the coefficients of the objective function
            int a = 0;
            float b = C[0];
            for(int i=1;i<C.size();i++){
                if(C[i]<b){
                    b = C[i];
                    a = i;
                }
            }
            return a;

}
int test1::findPivotRow(int pivotColumn)
{
            float positiveValues[row];
            vector<float> result(row,0);
            int negativeValueCount = 0;
            for(int i=0;i<row;i++){
                if(A[i][pivotColumn]>0){
                    positiveValues[i] = A[i][pivotColumn];
                }
                else{
                    positiveValues[i]=0;
                    negativeValueCount+=1;
                }
            }
            //checking the unbound condition if all the values are negative ones
            if(negativeValueCount==row){
                check = true;
            }
            else{
                for(int i=0;i<row;i++){
                    float value = positiveValues[i];
                    if(value>0){
                        result[i] = B[i]/value;

                    }
                    else{
                        result[i] = 0;
                    }
                }
            }
            //find the minimum's location of the smallest item of the B array
            float minimum = modulo;
            int location = 0;
            for(int i=0;i<sizeof(result)/sizeof(result[0]);i++){
                if(result[i]>0){
                    if(result[i]<minimum){
                        minimum = result[i];

                        location = i;
                    }
                }

            }
            return location;
}

void test1::CalculateSimplex()
{
            bool end = false;
            cout<<"initial array(Not optimal)"<<endl;
            print();
            cout<<" "<<endl;
            cout<<"final array(Optimal solution)"<<endl;
            while(!end){
                bool result = simplexAlgorithmCalculataion();
                if(result==true){
                    end = true;
                    }
            }
            cout<<"Answers for the Constraints of variables"<<endl;
            for(int i=0;i< A.size(); i++){  //every basic column has the values, get it form B array
                int count0 = 0;
                int index = 0;
                for(int j=0; j< row; j++){
                    if(A[j][i]==0.0){
                        count0 += 1;
                    }
                    else if(A[j][i]==1){
                        index = j;
                    }
                }
                if(count0 == row -1 ){
                    cout<<"variable"<<index+1<<": "<<B[index]<<endl;  //every basic column has the values, get it form B array
                }
                else{
                    cout<<"variable"<<index<<": "<<0<<endl;
                }
            }
           cout<<""<<endl;
           cout<<"maximum value: "<<maximum<<endl;  //print the maximum values
}
void solution()
{
    int colSizeA=5;  //should initialise columns size in A
    int rowSizeA = 3;  //should initialise columns row in A[][] vector
    // find the max-> 7x1+4x2
    //S.t 2x1+x2<=20; x1+x2<=18; x1<=8
    float C[]= {-7,-4,0,0,0};  //should initialis the c arry here
    float B[]={20,18,8};  // should initialis the b array here
    float a[3][5] = {    //should intialis the A[][] array here
                   { 2,  1,  1, 0, 0},
                   { 1,  1, 0, 1, 0},
                   { 1,  0,  0, 0, 1}
             };
        vector <vector<float> > vec(rowSizeA, vector<float>(colSizeA, 0));
        vector<float> b(rowSizeA,0);
        vector<float> c(colSizeA,0);
       for(int i=0;i<rowSizeA;i++){         //make a vector from given array
            for(int j=0; j<colSizeA;j++){
                vec[i][j] = a[i][j];
            }
       }
       for(int i=0;i<rowSizeA;i++){
            b[i] = B[i];
       }
        for(int i=0;i<colSizeA;i++){
            c[i] = C[i];
       }
      test1* test= new test1();
    test->Simplex(vec,b,c);
      test->CalculateSimplex();   
}
int main()
{
    solution();
}
