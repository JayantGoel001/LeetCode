class Foo {
public:
    int count = 0;
    mutex mtx;
    condition_variable cv;
    Foo() {
        count = 1;
    }
    

    void first(function<void()> printFirst) {
        unique_lock<mutex> lk(mtx);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        
        count++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lk(mtx);
        while(count != 2){
            cv.wait(lk);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        count++;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lk(mtx);
        while(count != 3){
            cv.wait(lk);
        }
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};