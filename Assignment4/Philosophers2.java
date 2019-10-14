import java.util.concurrent.TimeUnit;

public class Philosophers2 extends Thread {
    private static int NUM_PHIL = 5;
    private static int RunCnt[] = new int[NUM_PHIL]; // Counter for eating (Task 4)
    private final long period = 100 / NUM_PHIL; 
    
    private static Object[] forks = new Object[NUM_PHIL];
    private Thread[] phils = new Thread[NUM_PHIL];
	
    
    public static void main(String[] args) throws InterruptedException {
        // Create scheduler
        Philosophers2 p = new Philosophers2();
        Philosopher[] ph = new Philosopher[NUM_PHIL];
        // Create forks
        for(int i=0; i<NUM_PHIL; i++) forks[i]=new Object();
        for(int i=0; i<NUM_PHIL; i++){
            // Even though Deadlock doesnt occur this should fix it 
            if(i == NUM_PHIL - 1){
                ph[i]=new Philosopher(i, p, forks[i], forks[(i+1) % NUM_PHIL]);
            }else{
                ph[i]=new Philosopher(i, p, forks[i+1], forks[(i) % NUM_PHIL]);
            }    
        }
        // Start Scheduler
        p.start();

        sleep(10000); // Idle here

        // Request termination
        p.interrupt(); p.join();

        // Print stats
        for(int i = 0; i < NUM_PHIL; i++){ 
            System.out.print("ID: " + i + " Count: " + RunCnt[i] + "\n");
        }
    }
    /** Waiter thread  control **/
	public void run() {
		for(Thread p : phils) p.start();
		int currentPhils = 0;
		while(!interrupted()) {
		    synchronized(this) {
			  
                try { Thread.sleep(period); } catch(InterruptedException ie) { break; }
                Thread phil = phils[currentPhils];
                if(phil != null) {
                    synchronized(phil) { phil.notify(); }
                }
                currentPhils = (currentPhils + 1) % NUM_PHIL;
            }
        }   
		for(Thread p: phils) p.interrupt();
	}

    static class Philosopher extends Thread {
        private final Object leftFork, rightFork;
        private final int id;
        private long lastCall = 0;

        public Philosopher(int id, Philosophers2 scheduler, Object leftFork, Object rightFork) {
            this.id = id;
            scheduler.phils[id] = this;
            this.leftFork = leftFork;
            this.rightFork = rightFork;
        }
        
        private void eat() {
            long myPeriod = (lastCall == 0) ? 0 : System.nanoTime() - lastCall;
			lastCall = System.nanoTime();
			System.out.printf("Period from Philosopher %d: %.3f\n", id, myPeriod/1000000.0); 
            //System.out.println("Philosopher "+id+" is eating.");
            RunCnt[id]++;
            // delay
            try{Thread.sleep(100);}catch(InterruptedException ie){}
        }

        private void think() {
            //System.out.println("Philosopher "+id+" is thinking.");
            // delay
            try{Thread.sleep(100);}catch(InterruptedException ie){}
        }

        private void waiting() {
            //System.out.println("Philosopher "+id+" is waiting.");
            // delay
            try{Thread.sleep(100);}catch(InterruptedException ie){}
        }

        public void run() {
            while(!interrupted()) {
                    think();
                    waiting();
                    synchronized(leftFork){
                        // pick up forks
                        synchronized(rightFork){
                            //try{
                                eat();
                            //}catch(InterruptedException ie) {
                            //    break;
                            //}
                        }
                        // put down forks
                    }
                
            }
        }

    }
}
