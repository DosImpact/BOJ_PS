## C/C++/STL ���� to Python

# Section1. ���� ���� �Է� ���

[# Section2. ������ ������ �ڷ� ����](pythonBasic/Section1.md)

# Section2. ������ ������ �ڷ� ����

[# Section2. ������ ������ �ڷ� ����](pythonBasic/Section1.md)

## ����!

1. input() ���� sys.stdin.readline() �� �������.

2. ����Լ��� �ִ� ���, �ִ� ��� ���̸� ��������� �Ѵ�.

```
import sys sys.setrecursionlimit(10**8) # 10^8 ���� �ø�.

```

//2.2 ��½� �Ҽ��� ó���ϱ�
#include<iomanip>
setprecision(5)
fixed
eg)
double f = 3.1415926535;
cout<<setprecision(5)<<f; //�տ��� 5��°���� ���(�ݿø�����)

cout<<fixed<<setprecision(5)<<f; //�Ҽ��� �ڸ����� 5��° ���� ���(�ݿø� ����)

//3.13 bitset

//vector<bool> ���� , 1bit�� ����Ѵ�.

bitset<10> b2(88) //10�ڸ� 2������ ����µ�, ������ 88�� ��������
bitset<10> b2("10010")//10�ڸ� 2������ ����µ�, 2���� 10010�� ��������
bitset<n> b2 // �ַ�

    bitset<100000>a;
    bitset<100000>b;

    cin >> a >> b;

    cout << (a & b) << '\n'; //AND
    cout << (a | b) << '\n'; //OR
    cout << (a ^ b) << '\n';	//XOR
    cout << ~(a) << '\n';	//NOT
    cout << ~(b);		//NOT

eg)����

b2[i]
b2.test(i)

b.flip() b.flip(1) // 0 => 1, 1 => 0
b.set() b.set(1) // 0,1 => 1��
b.reset() b.reset(1) //0,1 => 0����

b.all() //��� 1?
b.any() //��� �Ѱ��� 1?
b.none() //��� 0?
b.count()//1�� ��ΰ�?

//���� ���� �ð� --> ���ʹ� N , set�� lgN, ����Ʈ�� 1
//count�� �ǹ� set������ ���缺 / multiset ������ ���� / STL�� count�� ����, map,unordered_map���� ���缺

Sec5. STL - Algorithm

//#5.9 ���� Ž��, ���� Ŀ���� ���� ����� ��찡 ���ѵ�,
binary_search(begin,end,value); //true or false
binary_search(begin,end,value,cmp); // true or false

---

//#5.12 ����

next_permutation(v.begin(),v.end()); //���� ����
prev_permutation(v.begin(),v.end()); //���� ����
