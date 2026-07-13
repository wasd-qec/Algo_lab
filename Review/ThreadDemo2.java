package Review;

public class ThreadDemo2 {
    public static void main(String[] args) {
        long start = System.currentTimeMillis();
        System.out.println("Before sleep, ms = " + (System.currentTimeMillis() - start));
        try {
            Thread.sleep(2000);
            System.out.println("Sleep time in ms = " + (System.currentTimeMillis() - start));
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
