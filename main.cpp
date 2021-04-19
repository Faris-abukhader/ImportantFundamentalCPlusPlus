#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include "vector"
#include "list"
using namespace std;
bool IsSubString (string mainString,string subString){
    int MstrLength = mainString.length();
    int SstrLength = subString.length();
    if(SstrLength>MstrLength)return false;
    for(int i=0;i<MstrLength-SstrLength;i++) if (mainString.substr(i,SstrLength)==subString){return true;}
    return false;
}
void PrintPascalTriangle(int n){
    static double a[100][100];
    int i,j;
    a[0][0] = 1;
    for(i=1;i<n;i++)
    for(j=0;j<=i;j++)
    a[i][j] = a[i-1][j-1]+a[i-1][j];
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
void EnterElementsToSortedArray(int a[],int size,int n){
    int i;
    for(i=0;i<size;i++){
        if(a[i]>n) break;
    }
    for(int j=i;j<size;j++){
        int y = a[j];
        a[j] = n;
        n = y;
    }
    for(int i=0;i<size;i++)cout<<a[i]<<endl;
}
void GiveFibonacciNumUntil(int n){
    int a[100]={1,1};
    for(int i=2;i<n;i++){
        a[i] = a[i-1]+a[i-2];
    }
    for(int i=0;i<n;i++){
        if (i%5==0)cout<<endl;
        cout<<a[i]<<" ";
    }
}
int Fibonacci(int n){
    if(n<2){
        return n;
    }else{
        return Fibonacci(n-1)+Fibonacci(n-2);
    }
}
bool IsPrimeNumber(int n){
    if(n<2)return false;
    for(int i=2;i<sqrt(n);i++)if(n%i==0)return false;
    return true;
}
bool IsPerfectNumber(int n){
    int sum=0;
    for(int i=1;i<n;i++)if(n%i==0)sum+=i;
    if(sum==n)return true;
    return false;
}
double GCM (int n1,int n2){
    if(n2==0)return n1;
    return GCM(n2, double(n1 % n2));
}
int GCMwithForLoop(int n1,int n2){
    int r=0;
    while (r=n1%n2) {
        n1=n2;
        n2=r;
    }
    return n2;
}
double LCM(int n1,int n2){
    if(n1==0&&n2==0)return 0;
    return abs(n1*n2)/GCM(n1, n2);
}
bool IsArmStrong(int n){
    int r=0,sum=0,temp=n;
    while (n>0) {
        r=n%10;
        n=n/10;
        sum+=r*r*r;
    }
    if(sum==temp)return true;
    return false;
}
int ArrayElementsSum(int a[],int size){
    if(size==0)return 0;
    else return ArrayElementsSum(a, size-1) +a[size-1];
}
int getTheInverseOf(int number){
    int res=0,flag=number>0 ?1:-1;
    if(number<0)number=-number;
    while (number!=0) {
        res = res*10 +number%10;
        number=number/10;
    }
    return res*flag;
}
int PowerRecursion(int number,int power){
    if(power==0)return 1;
     if(power==1)return number;
     else return number*PowerRecursion(number, power-1);
}
void MySwapUsingPointer(int* a,int* b){
    int t;t=*a;*a=*b;*b=t;
}
void SwapUsingLocation(int &a,int&b){
    int t;t=a;a=b;b=t;
}
void DeleteNumberElement(int num[],int n,int length){
    int i,j;
    for(i=0;i<length;i++)
        if (num[i]==n){
            for(j=i+1;j<length;j++)
            num[j-1]=num[j];
            length--;
            i--;
        }
}
bool IsPalindrome(char c[],int length){
    for(int i=0,j=length-1;i<j;i++,j--)if(c[i]==c[j])return true;
    return false;
}
bool IsPalindromeWithPointer(char str[],int length){
    char *pointerI,*pointerJ;
    pointerI =str;
    pointerJ =str+length-1;
    while (*pointerI == ' ')pointerI++;
    while (*pointerJ == ' ') pointerJ--;
    while ((pointerI<pointerJ)&&pointerJ!=pointerI) {
        pointerI++;
        pointerJ--;
    }
    if(pointerI!=pointerJ)return false;
    else return true;
}
int MaxValue(int a,int b){
    return (a>b)?a:b;
}
void FindTheMaxValueInTheMatrix(int size,int matrix[][3]){
    int maxVal=0,row=0,column=0;
    maxVal = matrix[0][0];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            maxVal = MaxValue(maxVal, matrix[i][j]);
            if(maxVal==matrix[i][j]){
                row = i;
                column = j;
            }
        }
    }
    cout<<"the Max Value is equal = "<<maxVal<<" and the row of it "<<row+1<<" , the column is "<<column+1<<endl;
}
void copyStr(char from[],char to[]){
    int i;
    for( i=0;from[i]!='\0';i++){
        to[i]=from[i];
    }
    to[i++]='\0';
}
void copyStrWithPointer(char *from,char*to){
    for (;*to++=*from++;);
    *to = '\0';
}
void DeleteCharFromString(char *str,char d){
    int i,j;
    for(i=j=0;str[i]!='\0';i++){
        if (str[i]!=d) {
            str[j++] = str[i];
        }
    }
    str[j]='\0';
}
void CopyFromToStartFromIndexI(char *from ,char *to,int FromIndex){
    int length = strlen(from);
    if(length<FromIndex) cout<<"No transformation"<<endl;
    else{
        from = from + FromIndex-1;
        for(int i=FromIndex;i<=length;i++){
            *to++ = *from ++;
        }
        *to = '\0';
    }
}
double FunctionToIntegrate(double x){
    return (x*x)+x-3;
}
double sumIntegral(double LowBoard,double upBoard,double n){
    double sum =0;
    double dx = (upBoard - LowBoard)/n;
    for(int i=0;i<n;i++){
        double x1 = LowBoard+i*dx;
        double functionValue =  FunctionToIntegrate(x1);
        double RectanleArea = functionValue*dx;
        sum +=RectanleArea;
    }
    return sum;
}
char * stringCatenate(char * str1,char *str2){
    char *p;
    for(p=str1;*p!='\0';p++);
    do{
        *p++ = *str2++;
    }while (*str2!='\0');
    *p='\0';
    return str1;
}
int RepeateTheNumManyTime(int num,int time){
    int n =  num;
    for(int i=1;i<=time;i++) num = n*((n*pow(10, i)+num)/n);
    return num;
}
double FunctionOne(int x){
    return (x*x)-(5*x)+6;
}
double DerivatedFunction(int x){
    return (2*x)-5;
}
double NewtonIterationMethod(double x,double precision){
    double h = FunctionOne(x) / DerivatedFunction(x);
    while (abs(x)>precision) {
        h=FunctionOne(x) / DerivatedFunction(x);
        x=x-h;
        cout<<h<<endl;
    }
    return x;
}
bool IsEven(int n){
    if(n%2!=0)return false;
    return true;
}
int NextPrime(int n){
    for(int i=n+1;;i++)if (IsPrimeNumber(i)) return i;
}
void GoldBach(int n){
    for (int i=2;i<=(n-i);i=NextPrime(i))if(IsPrimeNumber(n-1))cout<<i<<"+"<<n-i<<"="<<n<<endl;
}
double LegendrePolynomial(int n,int x){
    if (n==0)return 1;
    if (n==1)return x;
    return ((2*n-1)*x-LegendrePolynomial(n-1, x)-(n-1)*LegendrePolynomial(n-2, x))/n;
}
int TowerOfHanoi(int n,char from,char to,char auxiliary){
    int couter=0;
    if(n==1){
        cout<<"Move from "<<from<<" To "<<to<<endl;
        couter++;
    }else{
        couter+= TowerOfHanoi(n-1, from, auxiliary, to);
        cout<<"Move from "<<from<<" to "<<to<<endl;
        couter++;
        couter+= TowerOfHanoi(n-1, auxiliary, to, from);
    }
    return couter;
}
string Tostring(int n){
        int m=n,i=0,j=0;
        char s[100],ss[100];
        while(m>0){
            s[i++]= m%10 + '0';
            m/=10;
        }
        s[i]='\0';
        i=i-1;
        while(i>=0)ss[j++]=s[i--];
        ss[j]='\0';
        return ss;
}
int factorial(int n){
    if(n==1)return 1;
    else return n*factorial(n-1);
}
int BinarySearch(int a[],int n,int size){
        int start=0,end=size-1,mid=0;
            while (start<=end) {
                mid =(end+start)/2;
                if(a[mid]==n) return mid;
                if(a[mid]<n)start = mid-1;
                if(a[mid]>n)end = mid-1;
            }
            return mid;
}
void BubbleSort(int a[],int size){
        for(int i=0;i<size-1;i++)
            for(int j=0;j<size-i-1;j++)
                if(a[j]>a[j+1]){
                    int temp=a[j+1];
                    a[j+1] =a[j];
                    a[j]=temp;
                }
        for(int i=0;i<10;i++)cout<<a[i]<<endl;
}
void selectSort(int a[],int n){
    int k,t;
    for(int i=0;i<n-1;i++){
        k=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[k]){
                k=j;
                t=a[k];
                a[k]=a[i];
                a[i]=t;
            }
        }
    }
}
void QuickSort(int a[],int first ,int last){
    int pivot,i,j,temp;
    if(first<last){
        pivot=first;
        i=first;
        j=last;
        while (i<j) {
            while (a[i]<=a[pivot]) {
                i++;
            }
            while (a[j]>a[pivot]) {
                j--;
            }
            if(i<j){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
        temp=a[pivot];
        a[pivot]=a[j];
        a[j]=temp;
        QuickSort(a, 0, j-1);
        QuickSort(a,j+1, last);
    }
}
const int MAX_NAME_LENGTH = 30;
const int TABLE_SIZE = 10;
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} student;
student * hash_table[TABLE_SIZE];
unsigned int hashFunction(char *studnet){
    int length = strnlen(studnet,MAX_NAME_LENGTH);
    unsigned int hash_value = 0;
    for(int i=0;i<length;i++){
        hash_value += studnet[i];
        hash_value = (hash_value*studnet[i])%TABLE_SIZE;
    }
    return hash_value;
}
void initHashTable(){
    for(int i=0;i<TABLE_SIZE;i++){
        hash_table[i] = NULL;
    }
}
void printOutTable(){
    for(int i=0;i<TABLE_SIZE;i++){
        cout<<hash_table[i]<<endl;
    }
}
bool hashTableInsert(student *p){
    if(p==NULL)return false;
    int index = hashFunction(p->name);
    if(hash_table[index]!=NULL)return false;
    hash_table[index] = p;
    return true;
}
student *hashTableLookup(char *name){
    int index  = hashFunction(name);
    if(hash_table[index]!=NULL&&strcmp(hash_table[index]->name, name)==0){
        return hash_table[index];
    }
    return NULL;
}
void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left<n&&arr[left]>arr[largest])largest = left;
    if(right<n&&arr[right]>arr[largest])largest = right;
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--) heapify(arr, n, i);
    for(int i=n-1;i>=0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void Mymerge(int array[],int left,int mid,int right){
    int n1 = mid - left + 1 , n2 = right - mid;
    int leftArray[n1],RightArray[n2];
    for(int i=0;i<n1;i++)leftArray[i]=array[left+i];
    for(int j=0;j<n2;j++)RightArray[j]=array[mid+1+j];
    int i=0,j=0,k=left;
    while (i<n1&&j<n2) {
        if(leftArray[i]<=RightArray[j]){
            array[k]=leftArray[i];
            i++;
        }else{
            array[k]=RightArray[j];
            j++;
        }
        k++;
    }
    while (i<n1){
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j<n2){
        array[k] = RightArray[j];
        j++;
        k++;
    }
    
}
void mergeSort(int array[],int left,int right){
    if(left>=right)return;
    int mid = (left+right-1)/2;
    mergeSort(array, left, mid);
    mergeSort(array, mid+1, right);
    Mymerge(array, left, mid, right);
}
void bucketSort(int array[],int size){
    vector<int>bucket[size];
    for(int i=0;i<size;i++)bucket[int(array[i]/size)].push_back(array[i]);
    for(int i=0;i<size;i++)sort(bucket[i].begin(), bucket[i].end());
    int index=0;
    for(int i=0;i<size;i++){
        while (!bucket[i].empty()) {
            array[index++]= *bucket[i].begin();
            bucket[i].erase(bucket[i].begin());
        }
    }
}
class Graph {
    int V;
    list<int> *adj;
public:
    Graph(int v){
        this->V=v;
        adj = new list<int>[V];
    }
   void addEdge(int v,int w){
        adj[v].push_back(w);
    }
    void BFS(int s){
        bool *visted = new bool[V];
        for(int i=0;i<V;i++)visted[i]=false;
        list<int>queue;
        visted[s]=true;
        queue.push_back(s);
        list<int>::iterator i;
        while (!queue.empty()) {
            s=queue.front();
            cout<<s<<" ";
            queue.pop_front();
            for(i=adj[s].begin();i!=adj[s].end();i++)
            if(!visted[*i]){
                visted[*i]=true;
                queue.push_back(*i);
            }
        }
    }
};
void ConvertFromdecimalToHexdecimal(int num){
    char result[5],rem=0,index=0;
    while (num) {
        rem = num%16;
        if (rem<10){
            result[index] = rem+48;
            index++;
        }else {
            result[index] = rem+55;
            index++;
        }
        num=num/16;
    }
        for(int j=index;j>=0;j--)cout<<result[j];
        cout<<endl;
}
void MultiplyArrays(int arrayOne[][2],int arrayTwo[][2],int arrayOneRow,int arrayOneColumn,int arrayTwoRow,int arrayTwoColumn){
    if (arrayOneColumn!=arrayTwoRow) {
        cout<<"Unsatisfied Multi Arrays,Plese Check Again Array Size"<<endl;
        return;
    }
    int newArray[10][10];
    for (int i=0;i<arrayOneRow;i++)
    for (int j=0;j<arrayTwoColumn;j++)
    newArray[i][j]=0;
    for(int i = 0; i < arrayOneRow; ++i)
            for(int j = 0; j < arrayTwoColumn; ++j)
                for(int k = 0; k < arrayOneColumn; ++k)
                {
                    newArray[i][j] += arrayOne[i][k] * arrayTwo[k][j];
                }
    for(int i=0;i<arrayOneRow;i++){
        for(int j=0;j<arrayTwoColumn;j++)cout<<newArray[i][j]<<" ";
        cout<<endl;
    }
}
string reverseString (string str ){
  string result ;
  int n = str.length();
    for(int i=n-1,j=0;i!=j;i--,j++){
        char t;
        t= str[i];
        str[i] = str[j];
        str[j]=t;
    }
    for(int i=0;i<n;i++)result+=str[i];
  return result;
}
bool IsSquare(int n){
    return sqrt(n)*sqrt(n)==n;
}
string ToCamelCase(string str){
    int length = 0;
          char *temp=new char[100];
      strcpy(temp,str.c_str());
        for(length=0;temp[length]!='\0';length++);
      for(int i=0;temp[i]!='\0';i++)
        if(temp[i]=='_'||temp[i]=='-'){
            if(temp[i+1]>90)temp[i+1]-=32;
            for(int j=i+1;j<length;j++)temp[j-1]=temp[j];
            length--;
            i--;
        }
        temp[length]='\0';
        str="";
        for(int i=0;temp[i]!='\0';i++)str+=temp[i];
        return str;
}
void checkStrContext(){
    const int LINE_SIZE = 100;
    const int LINE_NUMBER = 20;
    int capital_letter=0,small_letter=0,number=0,symbol=0;
    char **Paragraph=new char*[LINE_NUMBER];
    for(int i=0;i<LINE_NUMBER;i++)Paragraph[i] = new char[LINE_SIZE];
    int row = 0;
    cout<<"Enter Your Paragraph:"<<endl;
    do {
        cin.getline(Paragraph[row], 100);
        for(int i=0;*(*(Paragraph+row)+i)!='\0';i++)
        if(*(*(Paragraph+row)+i)>=48&&*(*(Paragraph+row)+i)<=57)number++;
        else if(*(*(Paragraph+row)+i)>=65&&*(*(Paragraph+row)+i)<=90)capital_letter++;
        else if(*(*(Paragraph+row)+i)>=97&&*(*(Paragraph+row)+i)<=122)small_letter++;
        else if (*(*(Paragraph+row)+i)!=32)symbol++;
        row++;
    }while (strlen(Paragraph[row-1])>0);

    cout<<"Your Entered Results:"<<endl;
    cout<<capital_letter<<" capital letter(s) , "<<small_letter<<" small letter(s) , "<<number<<" number(s) , "<<symbol<<" symbol(s) ."<<endl;

}
char* GenterateBigInt(int numLength){
    char *bigInt = new char[100];
    int randomNum=0,i;
    for(i=0;i<numLength;i++){
        srand((unsigned) time(0));
        randomNum =(rand()%9)+1;
        bigInt[i]=randomNum;
      }
    bigInt[i]='\0';
    return bigInt;
}
int main() {
    cout<<"Hello Github"<<endl;
    return 0;
}

