
package lox;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List;
import java.util.Scanner;

public class Lox{

    public static void main(String[] args) throws IOException {
        if (args.length > 1) {
            System.out.println("Usage: jlox [script]");
            System.exit(64);
        } else if (args.length == 1) {
            runFile(args[0]);
        } else {
            runPrompt();
        }
    }

    private static void runFile(String path) throws IOException {
        byte[] bytes = Files.readAllBytes(Paths.get(path));
        run(new String(bytes, StandardCharsets.UTF_8));    
        if(hadError)  System.exit(65);
    }

    private static void runPrompt() {
        InputStreamReader input = new InputStreamReader(System.in);
        BufferedReader reader = new BufferedReader(input);

        for(;;){
            System.out.println("> ");
            String line = reader.readLine();
            if(line == null) break;
            run(line);
            hadError = false;
        }
    }

    private static void run(String source){
        Scanner scanner = new Scanner(source);

        List<Token> tokens = scanner.scanTokens();

        for(Token token: tokens){
            System.out.println(token);
        }
    }

    static void error(int line, String message){
        report(line, "", message);
    }
    
    static boolean hadError = false;
    private static void report(int line, String where, String message){
        System.err.println(
            "[line " + line + "] Error" + where + ": " + message);
        hadError = true;
    }




}