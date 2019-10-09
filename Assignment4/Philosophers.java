public class Philosophers {
    private static int NUM_PHIL = 5;
    private static int RunCnt[] = new int[NUM_PHIL];
    private static Object[] forks = new Object[NUM_PHIL];

    public static void main(String[] args) throws InterruptedException {
        Philosopher[] phils = new Philosopher[NUM_PHIL];
        // Create forks
        for(int i=0; i<NUM_PHIL; i++) forks[i]=new Object();
        for(int i=0; i<NUM_PHIL; i++) phils[i]=new Philosopher(i, forks[i], forks[(i+1) % NUM_PHIL]);
        // Start all Philosopher threads
        Thread.sleep(1); // Idle here
        // Request termination
        // Wait for all to finish
        // Print stats
    }

    static class Philosopher extends Thread {
        private final Object leftFork, rightFork;
        private final int id;
        public Philosopher(int id, Object leftFork, Object rightFork) {
            // Constructor
            // ...
        }

        private void eat() {
            System.out.println("Philosopher "+id+" is eating.");
            RunCnt[id]++;
            // delay
        }

        private void think() {
            System.out.println("Philosopher "+id+" is thinking.");
            // delay
        }

        private void waiting() {
            System.out.println("Philosopher "+id+" is waiting.");
            // delay
        }

        public void run( ) {
            while(/* ... */) {
                think();
                waiting();
                // pick up forks
                eat();
                // put down forks
            }
        }
    }


}
