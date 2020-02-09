## C/C++/STL ���� to Python

## ���� | Ÿ�� | �⺻���� | ����

```python

#  �⺻ ������
print(7/3)  # �Ҽ��� ì��� ������
print(7//3)  # �Ҽ��� ������ ������
print(7 % 3)  # mod
print(2 ** 3)  # pow

# �� �� ������
print(divmod(7, 3))  # Ʃ�÷� (2,1) ��ȯ.

# �� ��ȯ
print(type(3.3))  # float ��
print(int(3.3))  # �Ҽ��� ������ | int��
print(int('10'))  # string to int
print(str(10)) # int to str

# 2,8,16 ���� ����

print(0b101)  # �������� 5

print(0o10)  # �������� 8

print(0xF)  # �������� 15

# ��� ���� ���� ���ϱ�
# https://www.acmicpc.net/problem/11816
a = input()
if(a[0] == '0'):
    if(a[0:2] == '0x'):
        print(int(a[2:], 16))
    else:
        print(int(a[1:], 8))

else:
    print(int(a))

```

## ���� (����)

```python
# variable & type

a, b, c = 10, '20', 30

print(a, b, c)
print(type(a), type(b), type(c))

# Swap

a, c = c, a
print(a, b, c)

# variable => None | del

var1 = 10
del var1
# print(var1) # NameError: name 'var1' is not defined
var1 = None
print(var1)  # None

```

## ���� (�Է�,���)

```python
# input

var1 = input()  # input : 10 | str ������ �Էµ�
print(type(var1))

var1 = int(input())  # input : 10 | int�� �� ��ȯ
print(type(var1))


# input ������ �޾Ƽ�, �������� �����ϱ� ������ str�� ��

u, v = input().split()
print(u, v)
print(type(u), type(v))

# input �ٷ� int������ �޴� ���.

u, v = map(int, input().split())
print(u, v)
print(type(u), type(v))

# print ����  \n �� �ֱ�

a, b, c = map(int, input().split(','))  # input 10,20,30
print(a, b, c, sep='\n')  # output 10\n20\n30

# print ����  \n �� �ֱ�

a, b, c = map(int, input().split(','))  # input 10,20,30
print(a, b, c, sep='\n')  # output 10\n20\n30

print(a, end='')  # output 102030
print(b, end='')
print(c, end='\n')

print(a, end=' ')  # output 10 20 30
print(b, end=' ')
print(c, end='')


```

# python - �Է� ����, EOF ���� | ���� �׳� | spilt �̿��ؼ�

```python

# ���ڿ� ������ �׳� �ޱ�
a = input()
print(a)

# ������ ������ �˸;��� �ޱ� -> ����Ʈ�� ��ȯ��
a = input().split()
print(a)

# EOF(ctrl+Z) ���� ���� ���� �Է¹ޱ� (���� ���� �ϴ� ����)

import sys

for line in sys.stdin:
    a = line
    print(a)

# EOF(ctrl+Z) ���� ���� ���� �Է¹ޱ� (���� ���� �˸��� ���ڿ���)

import sys

for line in sys.stdin:
    a = line.split()
    print(a)

# EOF(ctrl+Z) ���� ���� a,b  �Է¹ޱ�

import sys

for line in sys.stdin:
    a, b = map(int, line.split())
    print(a + b)

#  ���� ���� ���ڿ� �ϳ��ϳ� �и��ϱ�

a = input()
print(list(a))

#  ���� ���� �� ���ڿ� �ϳ��ϳ� �и��ϱ�

a = input().split()
for e in a:
    print(list(e))

#  1234 ���� �Է½� , 1,2,3,4 �� �ϳ��� ���� �ޱ� ( ���� ó�� �Ұ���  )

a = list(input())
res = list(map(int, a))

print(res)

#  1234 ���� �Է½� , 1,2,3,4 �� �ϳ��� ���� �ޱ� ( ���� ó�� ���� )
ans = []
a = input().split()
for e in a:
    res = list(map(int, e))
    ans.extend(res)

print(ans)


```

## ���ٽ� | map ( �����Ҹ� 2�� ���Ҽ��ִ�. ) | filter (�迭���� ¦���ΰ�츸 ơ)

```python

# ���ٽ� | map ( �����Ҹ� 2�� ���Ҽ��ִ�. ) | filter (�迭���� ¦���ΰ�츸 ơ)
# (x,y) => x+y
# lamda x,y: x+y


def g(x): return x**2


(a, b, c) = map(g, [1, 2, 3])  # ���� ���� �� ���� 2����
print(a, b, c)


(a, b, c) = map(lambda x: x*2, [1, 2, 3])  # ���ٷ�, �� ���� 2��
print(a, b, c)

res = list(map(lambda x: x*2, [1, 2, 3]))  # ���ٷ�, �� ���� 2��
print(res)

wannaEven = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
res = list(filter(lambda e: e % 2 == 0, wannaEven))  # filter������Ʈ���� list�� ��ȯ�ϱ�.
print(res)

```

# bool �� ����

```python
if(True and False or not True):
    while(True):
        if(bool('False')):  # ��� ���ڿ��� ����!!!
            break
```

# ����Ʈ �����

```python
a = [] # Ȥ�� a = list()
b = list(range(10)) # 0���� 9���� range ��ü ����� list�� ��ȯ
print(b)

c = list(range(1, 5)) # [1, 2, 3, 4]
print(c)

c = list(range(1, 11, 2)) # [1, 3, 5, 7, 9] # 1���� 10���� 2������ | 11���� �ȵ�
print(c)

c = list(range(10, 0, -1)) # [10, 9, 8, 7, 6, 5, 4, 3, 2, 1] �� ���� 0�� �� ����.
print(c)
```

# Ʃ�� ����� ( Ʃ���� �б� ���� ����Ʈ )

```python
c = tuple(range(0, 10)) # range to tuple
print(c) # print (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
print(list(c)) # tuple to list
```

# ������ Ȱ��.

- ������ �ڷ����̶�: ����Ʈ, Ʃ��, range, string, bytes, bytearray = > �����̽� ��� ����!

## ���缺.

```python
a = [0, 1, 2, 'a', "hello", True, [0, 'dos', True], (0, 'impact', False)]

print(1 in a) # ��
print(10 in a) # ����
print('a' in a) # ��
print(True in a) # ��

print(1 not in a) # ����
print(10 not in a) # ��
print('a' not in a) # ����
print(True not in a) # ����

print('ll' in a[4]) # ��

print('dos' in a[6])  # ��
print('do' in a[6])  # ����
print('do' in a[6][1])  # ��

print('impact' in a[7])  # ��
print('act' in a[7])  # ����
print('act' in a[7][1])  # ��
```

# ������ with => len + \* del

```python
a = [1, 2, 3]
b = [4, 5, 6, 7, 8, 9, 10]
st = 'hello'
print(len(st)) # 5
print(a+b) # [1, 2, 3, 4, 5, 6]
print(a\*2) # [1, 2, 3, 1, 2, 3]
print(a[-1]) # 3 (�ڿ��� ù��°)

del a[1] # 1��° �ε��� ����
print(a) # [1, 3]
```

C���

//1.6 scanf ������ ������ �Է¹ޱ�
scanf("%ld",&x); //1234�Է�-> 1,2,3,4 1���� scanf
scanf("%10s",s); // ���ڿ� ���̰� 10�� (����) �� ����

//1.7 scanf ������ ���� �Է¹ޱ�
scanf("%d,%d",&x,&y); // 10,20 �̷����� ��ǥ�� ���� �� ����.
//����
while(scanf(...))�� EOF�Է½� ���ϰ��� -1 �� �Ǿ� while(��)�� �Ǿ� ���ѷ�Ǫ�� ���� �� ����

---

2. C++ ����� �⺻

//2.1 ���� �� �Է� �ޱ�
getline(cin,s); // s�� stirng ������

//2.2 ��½� �Ҽ��� ó���ϱ�
#include<iomanip>
setprecision(5)
fixed
eg)
double f = 3.1415926535;
cout<<setprecision(5)<<f; //�տ��� 5��°���� ���(�ݿø�����)

cout<<fixed<<setprecision(5)<<f; //�Ҽ��� �ڸ����� 5��° ���� ���(�ݿø� ����)

//2.3 ��� �ӵ���
cout<<i<<endl; //4272msec ���� + ��Ʈ���� flush�ϱ⶧���� ���� �ð��� �ɸ���.
cout<<i<<'\n'; //36msec
printf("%d\n",i); //20msec

//2.4 cin/cout �ӵ� �ø��� (scanf/printf�� ȥ������ ����!)
main�ٷ� ������

    cin.tie(NULL); cout.tie(NULL);
    ios_base::sync_with_stdio(false);

//2.5 C++11 �� auto
vector<int> d;
for(auto it = d.begin(); it != d.end(); it++){...}
for(auto& k:d){...}

//2.6 Range based for
vector<int> a = {1,2,3,4,5};
a.size(); // element�� ��ȯ unsinged long long ����
for(auto k : a){...}//�� ���� ������� ��ȯ
for(auto& k : a){...}//���� ������� ��ȯ // �� ���� ����

//2.7 C ��Ÿ��,C++ ��Ÿ�� �� string
const char cstr[] = "string"; // foreach������ 7��
string str = "string"; // foreach ������ 6��
// C��Ÿ���� ���ڿ����� null�� ���ԵǾ� �ֱ� ���� !!!

//2.8 C++ ���� �Լ� Lamda Function �͸� �Լ�(�Լ��� �����ε� �̸��� ����)

���� : [ĸó](�Լ� ����){�Լ� ����}
eg) cout<<[](int x,int y){return x+y;}(1,2)<<"\n";

eg) auto sum = [](int x,int y){return x+y;};
sum(1,2);

eg)
auto f = [&](){..} //�ܺκ��� ��� �����Ϸ��� ĸó�� &����

    auto f = [&x,y](){...} //�ܺθ�� x�� ����,y�� �� ����

    auto f = [&x,y]() mutable {...}// ������ �� �ȵ�..(?)

eg)
#include<functional> ��

function<int(int,int)> sum = [](int,int){....}
function<int()>
function<void()>
����� �ڷ��� ������ auto ���.

eg) ���ٷ� recursion �Ǻ���ġ ���� �Ǵ� vector�� ���� �ְ� foreach�����鼭 ��Ģ���� �غ���~

3. STL(1) ����

// STL = algorithm + container + function + iterator �� ����

//3.1 pair
#include<utility> �Ǵ� #include<vector> �Ǵ� #include<algorithm>

pair<int,int> p1 = make_pair(10,20);
pair<int,int> p1 = pair<int,int>(10,20);
pair<int,int> p2(10,20);

p1.first �� p1.second �� ����

//3.2 tuple
#include<tuple>
tuple<int,int,int> t1 = make_tuple(10,20,30);
cout<<get<0>(t1)<<'\n'; //<0>�ȿ��� ������ ����� ����.

//3.3 tie
#include<tuple>

eg)
int x,y,z;
tie(x,y,z) = make_tuple(1,2,3);
eg)
tie(b,a,ignore) = make_tuple(a,b,10);
tie(a,b) = make_pair(b,a); //swap���� ����

//3.4 vector
#include<vector>

eg)
vector<int> v1;
vector<int> v1(10); //ũ�� 10
vector<int> v1(10,5); // ũ�� 10�̰� �ʱⰪ ���� 5
vector<int> v1 = {1,2,3}; // �ʱ�ȭ ����Ʈ�� �̿��ؼ� �༺

eg)
v.push_back(); v.pop_back();
v.clear(); v.resize(); v.empty(); v.size();

v.begin(); v.end(); //������

v.front(); v.back(); v[1] //�� ����

v.emplace_back(1,2) //���Ұ� pair�� ���

eg)
v.insert(it,<t>)//�ش� ��ġ�� , ������
v.insert(it,10,<t>) // �ش� ��ġ��, ���� ��ŭ , ������
v.insert(it,d.begin(),d.end())// �ش� ��ġ��, ���� ù, ���� ��

eg)
v.erase(it);//����� ������
v.erase(it.start(),it.end())//����� ���� - ��

//3.5 deque
#include<deque>
deque<int> dq;

dq.push_back(t);
dq.push_front(t);
dq.pop_back();
dq.pop_front();

//3.6 list ���߿��� ����Ʈ : insert�� erase�� O(1)�� �ɸ�
#include<list>

list<int> l ={2,1,-5};
l.sort(); // �⺻ : ��������
l.sort(greater<int>());//��������
l.sort([](int& u,int& v){return abs(u)<abs(v);}); //Ŀ���� ����
l.reverse

//���� �����̳� : vector list deque
//���� �����̳� : set map

//3.8 set ���� ���� Ž���� log(n) �ɸ�
#include<set>

set<int> s1;
set<int> s2 = {1,2,3,4} // �ڵ� ������ ���� ���� �� �ߺ� ���ŵ�
set<int,greater<int>> s3 // �ڵ� ������ ���� �ϱ�

eg)
s1.insert(4); // ����
pair<set<int>::iterator, bool > result = s2.insert(4); //��� ��ȯ(���� ��ġ,���� ����)

    s1.erase(s.begin()); //����
    s1[] X //set�� ���� �� �ƴϾ�
    auto it = s.erase(s.begin()+1);//{1,2,3,4} -> {1,3,4}
    it = s.erase(it) //{1,3,4} -> {1,4}

eg)
set�� for �� foreach�� ��ȸ�� �����ϴ�. lgN

eg)
s = {1,3,5,7}
auto it = s.find(1); //{1,3,5,7} ù���� ���Ҹ� ����Ŵ
//������ s.end()�� ��ȯ��

    s.count(7) // ���� 7�� �? 1��

//3.8.2 multiset: ���� ���� �������� ���� �����ϴ�.

����)
<T>.count�� �ǹ�
map,unordered_map,set ������ 0�Ǵ� 1 (�������� �ʰ� ���� ���� )
multiset ������ 0�Ǵ� N( ���� �� ����)

//3.9 map - key�� value�� �̷����

#include<map>

map<int,int> d2 = {{1,2},{3,4}};
d2.size();//2
d2[1] //2 key�� �̿��ؼ� value����
d2[0] //0 ������ ���������. key�� 0 �� value �⺻��

eg)
if(d2[i]){...}//����Ȯ�� + ������ ����� ����
if(d2.count(i)){..} //���� Ȯ�θ�

eg)
map<int,int> d
//���빰�� iterator �� ����
for(auto it = d.begin(); it != d.end() ; it++){
cout<<it->first<<it->second;
}
//���빰�� pair
for(auto& p:d){
cout<<p.first<<p.second;
}

//�����̳� ����� : stack,queu,�켱ť,bitset : ���� �ڷᱸ���� ����.

//3.10 stack
#include<stack>

    stack<int> s1; //�⺻
    deque<int> d = {1,2,3}; stack<int> s2(d); //���� ��������
    stack<int,list<int>> s3; // ����Ʈ�� ���� �����

    s.push(<T>)
    s.pop()
    s.top()
    s.size()
    s.empty()
    s.emplace(5,6)

//3.11 queue
#include<queue>

    queue<int> q1;
    deque<int> d = {1,2,3}; queue<int> q3(d) // �����ε� ť ����
    queue<int,list<int>> q2; //����Ʈ�� ť �����

    q1.push(<t>)
    q1.pop()
    q1.front()
    q1.back()
    q1.size()
    q1.empty()
    q1.emplace_back()

//3.12 priority_queue - #include<queue>�� ���� ������.

#include<queue>

    priority_queue<int> pq;

    pq.push()
    pq.pop()
    pq.top() //  �켱 ť�� Ư���ϰ� front �� �ƴ� top �̴�. tree�� stack�� �����ϳ���.
    pq.empty() pq.size()

eg) �켱ť�� �⺻������ ������ ������ ���ĵȴ�. �׷� ������ �켱 ť�� ��� ���峪? 1. priority_queue<int,vector<int>,greater<int>> q3; 2. �Է½� pq.push(-x); ��½� -pq.top() // a<b �� -a > -b �̹Ƿ� -�� �ٿ� �ݴ������ �ְ�/ ��½� -�ٿ� ���󺹱�

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

Sec4. string

//4.1 ������.
string(char c[]);//���ڿ� ����
string(const char\*); //���ڿ�(���) ����
string(string s); // �ʱⰪ ����
string(); // "" �ʱ�ȭ
string(int,char);//������ � ���ڸ�

//4.2 EOF �Է�

while(cin>>s){...} //EOF ��� ���ϰ� T or F
while(scanf() == 2 ){...}
while(scanf() != EOF){...}
while(getline(cin,s))
while(getline(cin,s,char delimeter))// ���ڿ� �и�, char���� �и��� ���� ���ֱ�
->foreach �м��ϱ�~

//4.3 string s�� ���
s.c_str(); //printf("%s") ������ ����� �����ϴ�.
s.size();// s.size() - 1 �� unsigned long long �� MAX ��
s.length();//�ǹ̻�
s.empty();
s1 == s1 , s1 != s2, s1<s2 //������,�ٸ���,������������
s1+=s2;
s.push_back(char);
s.substr(); // s.substr(2,3)//hellow�� llo

s.append(int,char);//����,����
s.append(string);
s.append(const char\*);
s.append // �������� string�̹Ƿ� chain���� ����

s.insert(int,string);//��ġ ����
s.insert(int,int,char);//��ġ,����,��
s.insert(int,string,int,int);//������ġ, string ��, ��ġ, �

//4.4 ���� ���ڿ� ��ȯ
stoi(string);
stoi(string,int,int);//? int�� ���ں��� int������ ���� 10������ ����??
stll

stoul
stoull
stof
stod
stld

to_string(int �� double �Ǵ� float)

Sec5. STL - Algorithm

#include<algorithm> : ���� �ظ��ؼ��� ������ [begin,end) �̴�..

//#5.1 ī���� - ���ǿ� �´�, ���� �� ��ȯ O(N)
count(begin,end,value);
count_if(begin,end,p);

//#5.2 ��ġ ã�� - ���ǿ� �´� ���� ��ġ ��ȯ O(N)
find(begin,end,value);
find_if(begin,end,p); //������ end() ��ȯ

//#5.3 ���ҵ� (���ǿ� ������ ) ������ ä���
fill(begin,end,value);

//#5.4 ������
reverse(begin,end);

//#5.5 ȸ���ϱ�
rotate(begin,mid,end);
[mid,end)�� ������, [begin,mid)�� �ڷ� ��ġ �ٲٱ�.
rotate(begin,begin+1,end); //���������� ��ĭ�� �̵��ϱ�
rotate(begin,end-1,end); //�������� ��ĭ�� �̵��ϱ�

---

//#5.6 swap
swap(a,b) // int,vector<int>
swap(_(v.begin()), _(v.begin()+1) ); // ������ �ƴ�, �����̴�.!!

//#5.7 unique �������� ���ӵ� ���� �����ϰ� �ϳ��� ����� �ٽ� �ִ´�.
���� -> ����ũ -> erase
vector<int> v;
v.sort(); // 1.����
auto it = v.unique(v.begin(),v.end()); //2. ����ũ
erase(it,v.end()); // 3. ���� �����

//#5.8 ���� sort

sort(begin,end);
sort(begin,end,cmp);

sort(begin,end,greater<int>());
sort(begin,end,cmp);
bool cmp(const int& u, const int& v){return u > v ;}
sort(begin,end,[](const int& u,const int& v){return u > v; });

eg)pair�� �̿��� ���� ����, ���ڿ� -> �켱 ���� ������, �Z�� ���� ������
sort(s.begin,s.end,[](const string& u,const string& v){
return make_pair(-u.size(),u) < make_pair(-v.size(),v) ;} );

eg) ����ü�� Ŭ������ sort�� �Լ��� �ۼ��� �־�� ��. ���� �Լ� �Ǵ� cmp �ܺ� �Լ� �ۼ�.

//#5.8.2 ���� stable_sort ������ ������ ������ ������.
stable_sort(begin,end);
stable_sort(begin,end,cmp);

//#5.9 ���� Ž��, ���� Ŀ���� ���� ����� ��찡 ���ѵ�,
binary_search(begin,end,value); //true or false
binary_search(begin,end,value,cmp); // true or false

---

//#5.10 �ִ밪 �ּڰ� ã��

min(2,3); max(2,3);
min({1,2,3,4}); max({1,2,3,4});
min(p1,p2,cmp); max(p1,p2,cmp);

eg) ���� ���� ���ڿ� ���
min(s1,s2,[](string u,string v){ return u.size() < v.size(); });

minmax -> min��max�� pair���·� ��ȯ

min_element(begin,end);
min_element(begin,end,cmp);
//�ִ� �� �ּҰ��� ���ͷ����� ��ȯ.

eg) ���� -> min_element

    vector<string> ss = { "a","ab","abc","abcd"};
    auto it = min_element(ss.begin(),ss.end(),[](string u, string v){return u.size() < v.size();});
    cout<<*it;

//#5.11 �� ��, �� ũ�ų� ���� ù iterator ã��

lower_bound(begin,end,val); // val ���� ũ�ų� ���� ù iterator
lower_bound(begin,end,val,cmp);
upper_bound(begin,end,val); //val ���� ū ù iterator
upper_bound(begin,end,val,cmp);

//#5.12 ����

next_permutation(v.begin(),v.end()); //���� ����
prev_permutation(v.begin(),v.end()); //���� ����