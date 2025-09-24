class FizzBuzz {
private:
    int n;
    int i;
    mutex m;
    condition_variable c;

public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }
    void fizz(function<void()> printFizz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (i <= n && !(i % 3 == 0 && i % 5 != 0)) {
                c.wait(lock);
            }
            if (i > n) break;
            printFizz();
            i++;
            c.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (i <= n && !(i % 5 == 0 && i % 3 != 0)) {
                c.wait(lock);
            }
            if (i > n) break;
            printBuzz();
            i++;
            c.notify_all();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (i <= n && !(i % 15 == 0)) {
                c.wait(lock);
            }
            if (i > n) break;
            printFizzBuzz();
            i++;
            c.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            unique_lock<mutex> lock(m);
            while (i <= n && !(i % 3 != 0 && i % 5 != 0)) {
                c.wait(lock);
            }
            if (i > n) break;
            printNumber(i);
            i++;
            c.notify_all();
        }
    }
};