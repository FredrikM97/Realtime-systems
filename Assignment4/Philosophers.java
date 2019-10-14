public class Philosophers {
    private static int NUM_PHIL = 5;
    private static int RunCnt[] = new int[NUM_PHIL]; // Counter for eating (Task 4)
    private static Object[] forks = new Object[NUM_PHIL];
    private int currentFork = 0;

    public static void main(String[] args) throws InterruptedException {
        // Create scheduler
        Philosophers p = new Philosophers();

        Philosopher[] phils = new Philosopher[NUM_PHIL];
        // Create forks
        for(int i=0; i<NUM_PHIL; i++) forks[i]=new Object();
        for(int i=0; i<NUM_PHIL; i++) phils[i]=new Philosopher(i, forks[i], forks[(i+1) % NUM_PHIL];
        // Start all Philosopher threads
        for(Philosopher i : phils){
            i.start();
        }
        Thread.sleep(10000); // Idle here
        // Request termination
        for(Philosopher i : phils){
            i.requestStop();
            i.join();
        }
        // Wait for all to finish

        // Print stats
        for(int i = 0; i < NUM_PHIL; i++){ 
            System.out.print("ID: " + i + " Count: " + RunCnt[i])
        }
    }

    static class Philosopher extends Thread {
        private final Object leftFork, rightFork;
        private final int id;

        private volatile boolean stop = false;
        public synchronized void requestStop(){ stop = true; }


        public Philosopher(int id, Object leftFork, Object rightFork) {
            id = this.id;
            leftFork = this.leftFork;
            rightFork = this.rightFork;
        }
        
        private void eat() {
            System.out.println("Philosopher "+id+" is eating.");
            RunCnt[id]++;
            // delay
            Thread.sleep(2000);
        }

        private void think() {
            System.out.println("Philosopher "+id+" is thinking.");
            // delay
            Thread.sleep(2000);
        }

        private void waiting() {
            System.out.println("Philosopher "+id+" is waiting.");
            // delay
            Thread.sleep(1000);
        }

        public void run( ) {
            while(!stop) {
                synchronized(this){
                    think();
                    waiting();
                    // pick up forks
                    if(!rightFork[currentFork]) {

                        rightFork[currentFork] = true;
                         eat();
                        // put down forks
                        rightFork[currentFork] = false;
                    }
                    rightFork = (rightFork + 1)%NUM_PHIL;
                }
            }
        }
    }


}
