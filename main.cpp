#include <iostream>
#include <random>
#include <ctime>
#include "Matrix.h"

using namespace std;

void testIndexHandling() {
    srand((unsigned int)time(0));
    for (int i = 0; i < 1000; ++i) {
        int n = rand() % 20;
        int m = rand() % 20;
        vector<vector<int> > v(n, vector<int>(m));
        Matrix<int> m1(n, m);
        Matrix<int> m2(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                int x = rand();
                v[i][j] = x;
                m1[i][j] = x;
                m2.setIJ(i, j, x);
            }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (m1[i][j] != v[i][j] || m1.getIJ(i, j) != v[i][j] ||
                    m2[i][j] != v[i][j] || m2.getIJ(i, j) != v[i][j]) {
                    cerr << "testIndexHandling failed\n";
                    exit(1);
                }
    }
}

void testEqualNotEqual() {
    cout << "Enter size first matrix, first matrix, size second matrix, second matrix and get answer and etc\n";
    cout << "At the end write -1 -1\n";
    int n1, m1, n2, m2;
    while (true) {
        cin >> n1 >> m1;
        if (n1 == -1) {
            break;
        }
        Matrix<int> a(n1, m1);
        for (int i = 0; i < n1; ++i)
            for (int j = 0; j < m1; ++j)
                cin >> a[i][j];
        cin >> n2 >> m2;
        Matrix<int> b(n2, m2);
        for (int i = 0; i < n2; ++i)
            for (int j = 0; j < m2; ++j)
                cin >> b[i][j];
        if (a == b) {
            cout << "a == b is true\n";
        } else {
            cout << "a == b is false\n";
        }
        if (a != b) {
            cout << "a != b is true\n";
        } else {
            cout << "a != b is false\n";
        }
    }
}

void testCopyConstructor() {
    srand((unsigned int)time(0));
    for (int i = 0; i < 1000; ++i) {
        int n = rand() % 20;
        int m = rand() % 20;
        Matrix<int> a(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = rand();
        if (Matrix<int>(a) != a) {
            cerr << "testCopyConstructor failed\n";
            exit(1);
        }
    }
}

void testAssignment() {
    for (int i = 0; i < 1000; ++i) {
        int n = rand() % 20;
        int m = rand() % 20;
        Matrix<int> a;
        Matrix<int> b(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                b[i][j] = rand();
        a = b;
        if (a != b) {
            cerr << "testAssigment failed\n";
            exit(1);
        }
    }
}

void testUnaryPlus() {
    for (int i = 0; i < 1000; ++i) {
        int n = rand() % 20;
        int m = rand() % 20;
        Matrix<int> a(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = rand();
        if (a != (+a)) {
            cerr << "testUnaryPlus failed\n";
            exit(1);
        }
    }
}

void testUnaryMinus() {
    for (int i = 0; i < 1000; ++i) {
        int n = rand() % 20;
        int m = rand() % 20;
        Matrix<int> a(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = rand();
        Matrix<int> b = -a;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] + b[i][j]) {
                    cerr << "testUnaryMinus failed\n";
                    exit(1);
                }
    }
}

void testBinaryPlus() {
    cout << "Enter size first matrix, first matrix, size second matrix, second matrix and get answer and etc\n";
    cout << "At the end write -1 -1\n";
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == -1) {
            break;
        }
        Matrix<int> a(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        Matrix<int> b(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> b[i][j];
        Matrix<int> c = a + b;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cout << c[i][j] << ' ';
            cout << endl;
        }
    }
}

void testBinaryMinus() {
    cout << "Enter size first matrix, first matrix, size second matrix, second matrix and get answer and etc\n";
    cout << "At the end write -1 -1\n";
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == -1) {
            break;
        }
        Matrix<int> a(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        Matrix<int> b(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> b[i][j];
        Matrix<int> c = a - b;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                cout << c[i][j] << ' ';
            cout << endl;
        }
    }
}

void testMulOnNumber() {
    cout << "Enter size first matrix, first matrix, then enter number and get answer and etc\n";
    cout << "At the end write -1 -1\n";
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == -1)
            break;
        Matrix<int> a(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        int x;
        cin >> x;
        a = a * x;
        for (int i = 0; i < n; ++i) {
            for (int j  = 0; j < m; ++j)
                cout << a[i][j] << ' ';
            cout << endl;
        }
    }
}

void testDivOnNumber() {
    cout << "Enter size first matrix, first matrix, then enter number and get answer and etc\n";
    cout << "At the end write -1 -1\n";
    int n, m;
    while (true) {
        cin >> n >> m;
        if (n == -1)
            break;
        Matrix<int> a(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];
        int x;
        cin >> x;
        a = a / x;
        for (int i = 0; i < n; ++i) {
            for (int j  = 0; j < m; ++j)
                cout << a[i][j] << ' ';
            cout << endl;
        }
    }
}

void testMulOnMatrix() {
    cout << "Enter size first matrix, first matrix, size second matrix, second matrix and get answer and etc\n";
    cout << "At the end write -1 -1\n";
    int n1, m1, n2, m2;
    while (true) {
        cin >> n1 >> m1;
        if (n1 == -1) {
            break;
        }
        Matrix<int> a(n1, m1);
        for (int i = 0; i < n1; ++i)
            for (int j = 0; j < m1; ++j)
                cin >> a[i][j];
        cin >> n2 >> m2;
        Matrix<int> b(n2, m2);
        for (int i = 0; i < n2; ++i)
            for (int j = 0; j < m2; ++j)
                cin >> b[i][j];
        if (m1 != n2) {
            cout << "Don't correct enter\n";
            continue;
        }
        Matrix<int> c = a * b;
        for (int i = 0; i < c.getHeight(); ++i) {
            for (int j = 0; j < c.getWidth(); ++j)
                cout << c[i][j] << ' ';
            cout << endl;
        }
    }
}

void testPlusAssigment() {
    for (int i = 0; i < 100; ++i) {
        int n = rand() % 20;
        int m = rand() % 20;
        Matrix<int> a(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = rand();
        Matrix<int> b(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                b[i][j] = rand();
        Matrix<int> c = a + b;
        if ((a += b) != c) {
            cerr << "testPlusAssigment failed\n";
            exit(-1);
        }
        if (a != c) {
            cerr << "testPlusAssigment failed\n";
            exit(-1);
        }
    }
}

void testMinusAssigment() {
    for (int i = 0; i < 100; ++i) {
        int n = rand() % 20;
        int m = rand() % 20;
        Matrix<int> a(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = rand();
        Matrix<int> b(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                b[i][j] = rand();
        Matrix<int> c = a - b;
        if ((a -= b) != c) {
            cerr << "testMinusAssigment failed\n";
            exit(-1);
        }
        if (a != c) {
            cerr << "testMinusAssigment failed\n";
            exit(-1);
        }
    }
}

void testMulOnNumberAssigment() {
    for (int i = 0; i < 100; ++i) {
        int n = rand() % 20;
        int m = rand() % 20;
        Matrix<int> a(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = rand();
        int b = rand();
        Matrix<int> c = a * b;
        if ((a *= b) != c) {
            cerr << "testPlusAssigment failed\n";
            exit(-1);
        }
        if (a != c) {
            cerr << "testPlusAssigment failed\n";
            exit(-1);
        }
    }
}

void testDivOnNumberAssigment() {
    for (int i = 0; i < 100; ++i) {
        int n = rand() % 20;
        int m = rand() % 20;
        Matrix<int> a(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = rand();
        int b = rand();
        Matrix<int> c = a / b;
        if ((a /= b) != c) {
            cerr << "testPlusAssigment failed\n";
            exit(-1);
        }
        if (a != c) {
            cerr << "testPlusAssigment failed\n";
            exit(-1);
        }
    }
}

void testMulAssignment() {
    for (int i = 0; i < 100; ++i) {
        int n = rand() % 20;
        int m = rand() % 20;
        Matrix<int> a(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                a[i][j] = rand();
        Matrix<int> b(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                b[i][j] = rand();
        Matrix<int> c = a * b;
        if ((a *= b) != c) {
            cerr << "testPlusAssigment failed\n";
            exit(-1);
        }
        if (a != c) {
            cerr << "testPlusAssigment failed\n";
            exit(-1);
        }
    }
}

int main() {
    //testIndexHandling();
    //testEqualNotEqual();
    //testCopyConstructor();
    //testAssignment();
    //testUnaryPlus();
    //testUnaryMinus();
    //testBinaryPlus();
    //testBinaryMinus();
    //testMulOnNumber();
    //testDivOnNumber();
    //testMulOnMatrix();
    //testPlusAssigment();
    //testMinusAssigment();
    //testMulOnNumberAssigment();
    //testDivOnNumberAssigment();
    //testDivOnNumberAssigment();
}