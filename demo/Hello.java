import java.io.IOException;
import java.lang.management.ManagementFactory;

public class Hello {
    public static void main(String[] args) {
        try {
            Thread.sleep(1000);
        } catch (InterruptedException e) {
            System.out.println("HelloWorld interrupted");
        }
        long pid = ManagementFactory.getRuntimeMXBean().getPid();
        String p = ManagementFactory.getRuntimeMXBean().getSystemProperties().get("PID");
        System.out.println("PID: " + pid + " " + p);
        try {
            Runtime.getRuntime().exec("kill -SIGUSER1 " + pid);
        } catch (IOException e) {
            e.printStackTrace();
        }
        System.out.println("Hello, World");
    }
}
