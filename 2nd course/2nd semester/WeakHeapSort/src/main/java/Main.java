import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws IllegalArgumentException {
        Integer[] data;
        if (args.length < 1) {
            System.out.println("No arguments given!");
        } else {
            data = new Integer[args.length];
            for (int i = 0; i < args.length; i++)
                data[i] = Integer.parseInt(args[i]);
            WeakHeap wh = new WeakHeap(data);
            System.out.println("Building...");
            while (!wh.state.equals(WeakHeap.State.built)) {
                wh.buildStep();
            }
            System.out.println("state: "+wh.state);
            System.out.println(wh);
            System.out.println("Sorting...");
            while (!wh.state.equals(WeakHeap.State.done)) {
                switch (wh.state) {
                    case siftDown -> System.out.println("Join("+wh.joinId1+", "+wh.joinId2+")");
                    case delMin, built -> System.out.println("Saving min="+wh.values[0]);
                    default -> {}
                }
                System.out.println(wh);
                System.out.println("---------------------------------------------------");
                wh.heapsortStep();
            }
            System.out.println("state: "+wh.state);
            System.out.println(Arrays.toString(wh.values));
        }
    }
}
