class DiningPhilosophers {
    Semaphore fork[5];

public:
    DiningPhilosophers() {
        for (int i = 0; i < 5; i++) {
            fork[i].setCount(1);
        }
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        
        int left = philosopher;
        int right = (philosopher + 1) % 5;
        if (philosopher == 4) {
            fork[right].wait();
            pickRightFork();
            fork[left].wait();
            pickLeftFork();
        } else {
            fork[left].wait();
            pickLeftFork();
            fork[right].wait();
            pickRightFork();
        }
        eat();
        putLeftFork();
        fork[left].signal();
        putRightFork();
        fork[right].signal();
    }
};
