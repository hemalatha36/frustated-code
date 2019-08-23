#include <iostream.h>
long long int top = -1;

void push(int stack[], int x, long long int n) 
{
if (top == n - 1) 
{
cout << "Stack is full.Overflow condition!";
} 
else {
top = top + 1; 
stack[top] = x; 
}
}

bool isEmpty() {
if (top == -1) 
return true;
else
return false;
}

void pop() {

if (isEmpty()) {
cout << "Stack is empty. Underflow condition! " << endl;
} else {
top = top -1; 
}
}

int topElement(int stack[]) { return stack[top]; }

int main() {

long long int n, sum = 0;

cin >> n;

int a[n];
for (long long int i = 0; i < n; i++)
cin >> a[i];

sort(a, a + n);

int s[n];
for (long long int i = 0; i < n; i++) {

if (isEmpty()) {
push(s,a[i],n);
}

else
{
int index = top,flag=0;

if (topElement(s) < a[i]) {
pop();
push(s, a[i], n);
}

else
{
while (!isEmpty())
{
if (topElement(s) < a[i])
{
flag=1;
s[top]=a[i];
break;
}
top--;
}
top = index;

if (flag == 0) {
push(s, a[i], n);
}
}

}
}

while (!isEmpty()) {
sum = sum + topElement(s);
pop();
}
cout << sum << endl;

return 0;
}