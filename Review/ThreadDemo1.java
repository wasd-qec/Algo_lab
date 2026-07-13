package Review;

class TaskThread extends Thread {
    public TaskThread(String name) {
        super(name);
    }

    @Override
    public void run() {
        doDBProcessing();
    }

    private void doDBProcessing() {
        System.out.println("Heavy task processing - START " + Thread.currentThread().getName());
        try {
            Thread.sleep(5000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        System.out.println("Heavy task processing - END " + Thread.currentThread().getName());
    }
}

public class ThreadDemo1 {
    public static void main(String[] args) {
        System.out.println("Main program - START");
        Thread taskProcess = new TaskThread("t1");
        taskProcess.start();
        System.out.println("Main program - End");
    }
}
