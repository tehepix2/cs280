// how to read and use files in java

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        File in = new File ("Main.java");
        File out = new File ("copy of Main.java");

        try (Scanner scan = new Scanner(in); PrintWriter pw = new PrintWriter(out)) {
            while (scan.hasNext()) {
                pw.println(scan.nextLine());
            }
        } catch (FileNotFoundException e) {
            
            e.printStackTrace();
        }
        
    }
}