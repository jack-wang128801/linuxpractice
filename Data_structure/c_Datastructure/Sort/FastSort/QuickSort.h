#include<stdio.h>
#if 0
//快速排序
//时间复杂度:O(n)
//空间复杂度:O(1)
//
//最好|平均 O(log(n)*n)   最坏:O（n^2)
//空间复杂度:
//    递归过程的调用栈
//
//    二叉树的高度
//
//    最好|平均  O(log(n))
//    最坏O(n)
//
//稳定性:不稳定(Parition过程中无法保证顺序)
void Swap(int *a,int*b){
  int t=*a;
  *a=*b;
  *b=t;
}

//Hover法实现
//parition用三种方式实现
int  Parition_1(int array[],int left,int right){
  int begin=left;
  int end=right;//不能是right-1
  //基(基准值)在右,左先走
  //基在左，右先走
  while(begin<end){
    while(begin<end&&array[begin]<=array[right]){//=不能丢,可能造成死循环
      begin++;
    }
    //走到这里的时候,说明左边卡住了
    //左边有值大于array[right]了
    while(begin<end&&array[end]>=array[right]){
      end--;
    }
    //走到这里的时候右边也卡住了
    //右边有值大于基准值了
    Swap(array+begin,array+end);
  }
 Swap(array+begin,array+right);
  return begin;
}


//Paritiond的第二种实现方式:挖坑法
int  Parition_2(int array[],int left,int right){
  
  int pivot=array[right];//用来存储挖坑地点的值
  int begin=left;
  int end=right;
  while(begin<end){
    while(begin<end&&array[begin]<=pivot){
      begin++;
    }

    array[end]=array[begin];

    while(begin<end&&array[end]>=pivot){
      end--;
    }
    array[begin]=array[end];
  }
  array[begin]=pivot;
  return begin;
}



//NO3:前后下标法
int Parition_3(int array[],int left,int right){
  int d=left;
  for(int i=left;i<right;i++){
    if(array[i]<array[right]){
      Swap(array+d,array+i);
      d++;
    }
  }
   Swap(array+d,array+right);
   return d;
}
//区间被分成小，大，基准值

void _QuickSort(int array[],int left,int right){
  //终止条件 size==0||size==1
  //left==right  区间内还剩一个数
  //left>right 区间内没有数
  if(left==right){
    return;
  }
  if(left>right){
    return;
  }

  int div;//用于记录选出的基准值
  //比基准值大的要放到基准值左侧
  //比基准值小的放到基准值右侧
  //div=Parition_1(array,left,right);
  //div=Parition_2(array,left,right);
  div=Parition_2(array,left,right); 
  _QuickSort(array,left,div-1);
  //递归解决基准值左侧的数
  _QuickSort(array,div+1,right);
  //递归解决基准值右侧的数
}


void QuickSort(int *array,int size){
  _QuickSort(array,0,size-1);
}

void PrintSort(int array[],int size){
  for(int i=0;i<size;i++){
    printf("%d ",array[i]);
  }
  printf("\n");
}





void Test(){
  int array[]={1,9,3,4,2,7,6,8,0,5};
  int size=sizeof(array)/sizeof(array[0]);
  PrintSort(array,size);
  QuickSort(array,size);
  PrintSort(array,size);
}





//选择基准值的办法
//只有最右侧(或者最左侧)选为基准值
//很容易让快排退化成最差情况(数列有序  或者 逆序)
//其他选择基准值的办法
//1.三数取中
//mid=(left+right)/2
//array[left],array[mid],array[right]
//选择大小是中间的一个数做为基准值
//2.随机,从left到right 随机选一个下标
//
//
//
#endif


//非递归的写法
//需要利用栈实现


#include<stack>

void _QuickSort(int array[],int left,int right){


  int _left;
  int _right;
  std::stack<int> s;
  s.push(right);
  s.push(left);
  while(!s.empty()){
    _left=s.top();
    s.pop();
    _right=s.top();
    s.pop();

    if(_left>=_right){
      continue;
    }

    int d=Parition_1(array,_left,_right);
    //d+1 ,right 
    s.push(_right);
    s.push(d+1);
    //_left ,d-1
    s.push(d-1);
    s.push(_left);
  }
}





