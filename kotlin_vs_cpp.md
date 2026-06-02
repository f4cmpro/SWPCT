# Kotlin ⇄ C++ — Bảng tham chiếu cú pháp

Tài liệu ánh xạ cú pháp, kiểu dữ liệu và cấu trúc dữ liệu giữa **Kotlin** và **C++**.

---

## 1. Biến & Hằng số

| C++ | Kotlin | Ghi chú |
|---|---|---|
| `int x = 5;` | `var x: Int = 5` / `var x = 5` | biến thay đổi được |
| `const int x = 5;` | `val x = 5` | hằng (read-only) |
| `auto x = 5;` | `val x = 5` | suy luận kiểu |
| `int x;` (chưa gán) | `var x: Int` | Kotlin yêu cầu khởi tạo trước khi dùng |

---

## 2. Kiểu dữ liệu cơ bản

| C++ | Kotlin | Kích thước |
|---|---|---|
| `bool` | `Boolean` | 1 bit (logic) |
| `char` | `Char` | 16-bit (Unicode) trong Kotlin |
| `short` | `Short` | 16-bit |
| `int` | `Int` | 32-bit |
| `long long` | `Long` | 64-bit |
| `float` | `Float` | 32-bit |
| `double` | `Double` | 64-bit |
| `std::string` | `String` | chuỗi |
| `unsigned int` | `UInt` | không dấu (Kotlin 1.5+) |

---

## 3. Hàm

```cpp
// C++
int add(int a, int b) {
    return a + b;
}
```
```kotlin
// Kotlin
fun add(a: Int, b: Int): Int {
    return a + b
}
// rút gọn (expression body)
fun add(a: Int, b: Int) = a + b
```

| C++ | Kotlin |
|---|---|
| `void f()` | `fun f()` (trả về `Unit`) |
| `int f(int a = 1)` (default arg) | `fun f(a: Int = 1)` |
| Overloading | Overloading + tham số mặc định |
| Con trỏ hàm | Lambda / function reference `::f` |

---

## 4. Điều kiện

```cpp
// C++
if (x > 0) { ... } else { ... }
```
```kotlin
// Kotlin
if (x > 0) { ... } else { ... }
val r = if (x > 0) "pos" else "neg"   // if là biểu thức
```

### switch / when
```cpp
// C++
switch (x) {
    case 1: ...; break;
    default: ...;
}
```
```kotlin
// Kotlin
when (x) {
    1 -> ...
    in 2..5 -> ...
    else -> ...
}
```

---

## 5. Vòng lặp

| C++ | Kotlin |
|---|---|
| `for (int i = 0; i < n; i++)` | `for (i in 0 until n)` |
| `for (int i = 0; i <= n; i++)` | `for (i in 0..n)` |
| `for (int i = n-1; i >= 0; i--)` | `for (i in n-1 downTo 0)` |
| `for (int i = 0; i < n; i += 2)` | `for (i in 0 until n step 2)` |
| `for (int x : arr)` | `for (x in arr)` |
| `while (cond)` | `while (cond)` |
| `do { } while (cond)` | `do { } while (cond)` |

---

## 6. Null Safety

| C++ | Kotlin |
|---|---|
| `int* ptr = nullptr;` | `var x: Int? = null` |
| `if (ptr != nullptr)` | `if (x != null)` |
| `ptr->f()` | `x?.f()` (safe call) |
| — | `x ?: default` (Elvis operator) |
| — | `x!!` (assert not-null) |

---

## 7. Class & OOP

```cpp
// C++
class Animal {
public:
    string name;
    Animal(string n) : name(n) {}
    void speak() { cout << name; }
};
```
```kotlin
// Kotlin
class Animal(val name: String) {
    fun speak() { println(name) }
}
```

| C++ | Kotlin |
|---|---|
| `class A : public B` | `class A : B()` |
| `virtual void f()` | `open fun f()` |
| `void f() override` | `override fun f()` |
| `abstract` (pure virtual) | `abstract fun f()` |
| `struct` | `data class` (gần tương đương) |
| `static` member | `companion object` |
| `public` / `private` | `public` (mặc định) / `private` |

---

## 8. Mảng & Vector

| C++ | Kotlin |
|---|---|
| `int arr[5]` | `val arr = IntArray(5)` |
| `int arr[] = {1,2,3}` | `val arr = intArrayOf(1, 2, 3)` |
| `vector<int> v` | `val v = mutableListOf<Int>()` |
| `v.push_back(x)` | `v.add(x)` |
| `v.pop_back()` | `v.removeAt(v.lastIndex)` |
| `v.size()` | `v.size` |
| `v[i]` | `v[i]` |
| `v.empty()` | `v.isEmpty()` |
| `sort(v.begin(), v.end())` | `v.sort()` |

### Mảng 2 chiều
```cpp
vector<vector<int>> grid(r, vector<int>(c, 0));
```
```kotlin
val grid = Array(r) { IntArray(c) }
```

---

## 9. Cấu trúc dữ liệu (STL ⇄ Kotlin)

| C++ | Kotlin |
|---|---|
| `stack<int>` | `ArrayDeque<Int>()` — `addLast`/`removeLast`/`last` |
| `queue<int>` | `ArrayDeque<Int>()` — `addLast`/`removeFirst`/`first` |
| `deque<int>` | `ArrayDeque<Int>()` |
| `priority_queue<int>` (max) | `PriorityQueue<Int>(reverseOrder())` |
| `priority_queue<...greater>` (min) | `PriorityQueue<Int>()` |
| `set<int>` | `TreeSet<Int>()` / `sortedSetOf()` |
| `unordered_set<int>` | `mutableSetOf<Int>()` (HashSet) |
| `map<K,V>` | `TreeMap<K,V>()` / `sortedMapOf()` |
| `unordered_map<K,V>` | `mutableMapOf<K,V>()` (HashMap) |
| `pair<A,B>` | `Pair(a, b)` / `a to b` |
| `tuple<A,B,C>` | `Triple(a, b, c)` |
| `list<int>` | `LinkedList<Int>()` |

### Thao tác Map
```cpp
// C++
m["key"] = val;
m.count("key");
for (auto& [k, v] : m) { ... }
```
```kotlin
// Kotlin
m["key"] = value
"key" in m
for ((k, v) in m) { ... }
```

---

## 10. Nhập / Xuất

| C++ | Kotlin |
|---|---|
| `cin >> x;` | `val x = readLine()!!.toInt()` |
| `cout << x;` | `print(x)` |
| `cout << x << endl;` | `println(x)` |
| `getline(cin, s)` | `val s = readLine()!!` |
| Đọc nhiều số 1 dòng | `readLine()!!.split(" ").map { it.toInt() }` |

---

## 11. Khác biệt cú pháp đáng chú ý

| Khía cạnh | C++ | Kotlin |
|---|---|---|
| Dấu chấm phẩy | Bắt buộc `;` | Không cần |
| Khai báo kiểu | Trước tên: `int x` | Sau tên: `x: Int` |
| Entry point | `int main()` | `fun main()` |
| Namespace | `using namespace std;` | `import ...` |
| Con trỏ / tham chiếu | `*`, `&`, `->` | Không có con trỏ trực tiếp |
| Quản lý bộ nhớ | Thủ công / RAII | Garbage Collector |
| String template | `"a" + to_string(x)` | `"a $x"` / `"${expr}"` |

---

## 12. Tách chuỗi (Split String)

| C++ | Kotlin |
|---|---|
| `stringstream ss(s); string tok; while(ss >> tok)` | `s.split(" ")` |
| `stringstream` với delimiter tùy chỉnh | `s.split(",")` |
| `s.substr(pos, len)` | `s.substring(pos, pos + len)` |
| `s.find(delim)` + vòng lặp thủ công | `s.split(delim)` trả về `List<String>` |

```cpp
// C++ — tách theo khoảng trắng
#include <sstream>
string s = "1 2 3";
stringstream ss(s);
string tok;
while (ss >> tok) {
    // xử lý tok
}

// C++ — tách theo delimiter tùy chỉnh
string s = "a,b,c";
stringstream ss(s);
string tok;
while (getline(ss, tok, ',')) {
    // xử lý tok
}
```
```kotlin
// Kotlin — tách theo khoảng trắng
val parts = "1 2 3".split(" ")          // ["1", "2", "3"]

// Kotlin — tách theo delimiter tùy chỉnh
val parts = "a,b,c".split(",")          // ["a", "b", "c"]

// Tách và chuyển kiểu ngay
val nums = "1 2 3".split(" ").map { it.toInt() }   // [1, 2, 3]

// Tách với nhiều delimiter
val parts = "a b,c".split(" ", ",")    // ["a", "b", "c"]

// Tách với regex
val parts = "a  b   c".split(Regex("\\s+"))  // ["a", "b", "c"]
```

---

## 13. String Template (nội suy chuỗi)

```cpp
// C++
string s = "Tổng = " + to_string(a + b);
```
```kotlin
// Kotlin
val s = "Tổng = ${a + b}"
val t = "Tên: $name"
```

---

> **Tóm tắt:** Kotlin ngắn gọn hơn, có null safety tích hợp, dùng GC thay vì quản lý bộ nhớ thủ công, và gộp `stack`/`queue`/`deque` của C++ thành một `ArrayDeque` duy nhất.

---

## 14. Include headers trong C++

### Kiểu dữ liệu cơ bản & I/O
```cpp
#include <iostream>   // cin, cout, endl
#include <string>     // std::string
#include <cstdio>     // printf, scanf, freopen
```

### Cấu trúc dữ liệu
```cpp
#include <vector>           // vector<T>
#include <array>            // array<T, N>
#include <stack>            // stack<T>
#include <queue>            // queue<T>, priority_queue<T>
#include <deque>            // deque<T>
#include <list>             // list<T> (linked list)
#include <forward_list>     // forward_list<T> (singly linked)
```

### Set & Map
```cpp
#include <set>              // set<T>, multiset<T>
#include <unordered_set>    // unordered_set<T>
#include <map>              // map<K,V>, multimap<K,V>
#include <unordered_map>    // unordered_map<K,V>
```

### Tiện ích
```cpp
#include <utility>          // pair<A,B>, make_pair, swap
#include <tuple>            // tuple<A,B,C>, make_tuple, get<>
#include <algorithm>        // sort, min, max, reverse, find, ...
#include <numeric>          // accumulate, iota, gcd, lcm
#include <functional>       // greater<T>, less<T>, function<>
#include <iterator>         // begin, end, next, prev
```

### Toán học & xử lý số
```cpp
#include <cmath>            // sqrt, pow, abs, ceil, floor, log
#include <climits>          // INT_MAX, INT_MIN, LLONG_MAX, ...
#include <cfloat>           // FLT_MAX, DBL_MAX, ...
#include <cstdlib>          // abs, rand, srand, atoi
```

### Chuỗi
```cpp
#include <string>           // string
#include <sstream>          // stringstream (parse chuỗi)
#include <cctype>           // isdigit, isalpha, toupper, tolower
```

### Shortcut phổ biến trong competitive programming
```cpp
// Thay vì include từng cái, dùng:
#include <bits/stdc++.h>    // include TẤT CẢ (chỉ dùng khi CP, GCC only)
using namespace std;
```

> **Lưu ý:** `#include <bits/stdc++.h>` chỉ hoạt động trên **GCC** (Linux/MinGW), không dùng được trên MSVC (Windows) hay Clang (macOS mặc định).
