import java.io.*;
import java.net.*;

public class Cliente {
    public static void main(String[] args) {
        final String HOST = "localhost";
        final int PORT = 8080;

        try (Socket socket = new Socket(HOST, PORT);
             DataInputStream in = new DataInputStream(socket.getInputStream());
             DataOutputStream out = new DataOutputStream(socket.getOutputStream());
             BufferedReader reader = new BufferedReader(new InputStreamReader(System.in))) {

            int num;

            while (true) {
                System.out.print("Ingrese un número entero (0 para salir): ");
                num = Integer.parseInt(reader.readLine());

                // Enviar el número al servidor
                out.writeInt(num);
                out.flush();

                // Terminar si se envía cero
                if (num == 0) {
                System.out.print("Conexión terminada");
                    break;
                }

                // Leer la respuesta del servidor
                int resultado = num+1;
                System.out.println("El servidor respondió: " + resultado);
            }

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

