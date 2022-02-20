import java.util.Arrays;
import java.util.LinkedList;

import org.apache.commons.lang3.StringUtils;

public class WeakHeap {
    // Data structure fields
    int length;
    int[] values;
    int[] bits;
    /* to add element -> add to the bottom and siftUp
     * to remove element -> swap with last and siftDown
     * */

    // Algorithm fields
    public enum State {
        preBuilding,
        building,
        built,
        delMin,
        preSiftDown,
        siftDown,
        done
    }

    public State state = WeakHeap.State.preBuilding;
    public int joinId1 = 0;
    public int joinId2 = 0;
    int initialLength;
    int buildIterator;

    WeakHeap(@org.jetbrains.annotations.NotNull Integer[] data) {
        this.length = data.length;
        this.values = new int[length];
        this.bits = new int[length];
        for (int i = 0; i < length; i++) {
            this.values[i] = data[i];
            this.bits[i] = 0;
        }
        initialLength = length;
        buildIterator = length-1;
    }

    @Override
    public String toString() {
        if (length < 1)
            return "";
        StringBuilder result = new StringBuilder();
        LinkedList<Integer> row = new LinkedList<>();
        LinkedList<Integer> new_row = new LinkedList<>();
        int lineSize = 64;
        int cellSize = lineSize;
        int height = 1; // could be 1+lb(length-1)
        for (int i = length - 1; i > 0; i /= 2) {
            height++;
        }

        result.append(StringUtils.center("" + values[0], lineSize / 2));
        row.addLast(1);
        for (int level = 1; level <= height; level++) { // add each layer
            result.append("\n");
            while (!(row.isEmpty())) {
                Integer node = row.pollFirst();
                if (node == null || !(node < length)) {
                    result.append(" ".repeat(cellSize));
                    new_row.addLast(null);
                    new_row.addLast(null);
                } else {
                    result.append(StringUtils.center("" + values[node], cellSize));
                    new_row.addLast(2 * node + bits[node]);     // add Left child
                    new_row.addLast(2 * node + 1 - bits[node]);   // add right child
                }
            }
            row = new_row;
            new_row = new LinkedList<>();
            cellSize /= 2;
        }
        result.append("\n");
        result.append(Arrays.toString(values));
        return result.toString();
    }

    public boolean join(int v, int w) {
        if (values[v] < values[w]) {
            // swap values
            values[v] ^= values[w];
            values[w] ^= values[v];
            values[v] ^= values[w];
            // change bit
            bits[v] = 1 - bits[v];
            return true;
        }
        return false;
    } // проталкивает минимум из v наверх в w

    public int up(int v) {
        if (((v % 2) ^ (bits[v / 2])) == 1)
            return v / 2;
        return up(v / 2);
    } // returns Right parent

    void siftUp(int v) {
        int w;
        while (join(v, w = up(v)))
            v = w;
    } // sifts WeakHeap

    int siftDown() {
        if (length < 1) {
            return values[0];
        }
        int min = values[0];                // save min
        length--;                           // delete min
        values[0] ^= values[length];        // swap values
        values[length] ^= values[0];        // .
        values[0] ^= values[length];        // .
        if (length < 2)                     // 1-node case (only root)
            return min;                     // .
        int v = 1;                          // greedy go down to the left
        while (2 * v + bits[v] < length)    // .
            v = 2 * v + bits[v];            // .
        while (v > 0) {                     // siftDown
            join(v, 0);                  // .
            v /= 2;                         // .
        }
        return min;
    } // Deletes minimum

    public void build() {
        while (!state.equals(State.built))
            buildStep();
    } // makes WeakHeap a correct one

    public void heapsort() {
        while (!state.equals(State.done))
            heapsortStep();
        length = initialLength;
    }

    public boolean heapsortStep() {
        boolean swapped = false;
        switch (state) {
            case preBuilding, building -> {
            }
            case built, delMin -> {
                if (length < 2) {   // length == 0 or length == 1
                    state = State.done;
                    break;
                }
                length--;
                values[0] ^= values[length];
                values[length] ^= values[0];
                values[0] ^= values[length];
                state = State.preSiftDown;
                joinId1 = 1;
                joinId2 = 0;
                while (2 * joinId1 + bits[joinId1] < length)
                    joinId1 = 2 * joinId1 + bits[joinId1];     // left Child
                joinId1 *= 2;
                if (length == 1) {
                    state = State.done;
                }
            }
            case preSiftDown -> {
                joinId1 /=2;
                if (joinId1 > 0)
                    state = State.siftDown;
                else
                    state = State.delMin;
            }
            case siftDown -> {
                swapped = join(joinId1, joinId2);
                state = State.preSiftDown;
            }
            case done -> length = initialLength;
        }

        return swapped;
    }

    public boolean buildStep() {
        boolean swapped = false;
        switch (state) {
            case preBuilding -> {
                if (buildIterator < 1)
                    state = State.built;
                else {
                    joinId1 = buildIterator;
                    joinId2 = up(buildIterator);
                    state = State.building;
                }
            }
            case building -> {
                swapped = join(joinId1, joinId2);
                buildIterator--;
                if (buildIterator < 1)
                    state = State.built;
                else
                    state = State.preBuilding;
            }
            case delMin, siftDown, built -> {}
        }
        return swapped;
    }
}
