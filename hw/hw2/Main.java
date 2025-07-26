// how to read and use files in java

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayList;





public class Main {
    static ArrayList<String> allStrings = new ArrayList<>();
    static ArrayList<String> strings = new ArrayList<>();

    public static void main(String[] args) {
        File out = new File("input.txt");
        try (Scanner scan = new Scanner(out);) {
            while (scan.hasNext()) {
                String line = scan.nextLine();
                allStrings.add(line);
                strings.add(line);
            }


            for (int i = 0; i < strings.size(); i++) {
                if (strings.get(i).isEmpty()) {
                    System.out.println("The string \"" + allStrings.get(i) + "\" is not in the language.");
                } else if (A(i) && strings.get(i).isEmpty()) {
                    System.out.println("The string \"" + allStrings.get(i) + "\" is in the language.");
                } else {
                    System.out.println("The string \"" + allStrings.get(i) + "\" is not in the language.");
                }
            }

        } catch (IOException e) {
            System.out.println("Failed to read file.");
        }
    }

    static boolean A(int i) { // A -> I = E
        String backup = strings.get(i);

        if (!I(i)) return false;

        if (strings.get(i).isEmpty() || strings.get(i).charAt(0) != '=') {
            strings.set(i, backup);
            return false;
        }

        strings.set(i, strings.get(i).substring(1));

        if (!E(i)) {
            strings.set(i, backup);
            return false;
        }

        return true;
    }

    static boolean E(int i) { // E -> P O P | P
        String backup = strings.get(i);

        if (P(i)) {
            if (O(i)) {
                if (P(i)) return true;
            }
            strings.set(i, backup);
        }

        return P(i);
    }

    static boolean O(int i) {
        String s = strings.get(i);
        if (s.length() >= 2 && s.substring(0,2).equals("**")) {
            strings.set(i, s.substring(2));
            return true;
        }

        if (!s.isEmpty()) {
            char c = s.charAt(0);
            if ("+-*/".indexOf(c) != -1) {
                strings.set(i, s.substring(1));
                return true;
            }
        }

        return false;
    }

    static boolean P(int i) {
        String backup = strings.get(i);

        if (I(i)) return true;
        strings.set(i, backup);

        if (L(i)) return true;
        strings.set(i, backup);

        if (U(i)) {
            if (P(i)) return true;
        }

        strings.set(i, backup);
        if (!strings.get(i).isEmpty() && strings.get(i).charAt(0) == '(') {
            strings.set(i, strings.get(i).substring(1));
            if (E(i) && !strings.get(i).isEmpty() && strings.get(i).charAt(0) == ')') {
                strings.set(i, strings.get(i).substring(1));
                return true;
            }
        }

        return false;
    }

    static boolean U(int i) {
        if (!strings.get(i).isEmpty()) {
            char c = strings.get(i).charAt(0);
            if (c == '+' || c == '-' || c == '!') {
                strings.set(i, strings.get(i).substring(1));
                return true;
            }
        }

        return false;
    }

    static boolean I(int i) {
        if (!C(i)) return false;

        while (C(i)) { }

        return true;
    }

    static boolean C(int i) {
        if (!strings.get(i).isEmpty()) {
            char c = strings.get(i).charAt(0);
            if (c >= 'a' && c <= 'z') {
                strings.set(i, strings.get(i).substring(1));
                return true;
            }
        }

        return false;
    }

    static boolean L(int i) {
        if (!D(i)) return false;

        while (D(i)) { }

        return true;
    }

    static boolean D(int i) {
        if (!strings.get(i).isEmpty()) {
            char c = strings.get(i).charAt(0);
            if (c >= '0' && c <= '9') {
                strings.set(i, strings.get(i).substring(1));
                return true;
            }
        }

        return false;
    }
}
