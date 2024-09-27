import java.io.*;
import java.net.*;

public class ServidorJavaE1 {
    public static void main(String[] args) {
        if (args.length != 1) {
            System.out.println("Uso: java Servidor <puerto>");
            return;
        }

        int puerto = Integer.parseInt(args[0]);
        
        try (ServerSocket serverSocket = new ServerSocket(puerto)) {
            System.out.println("Servidor escuchando en el puerto " + puerto);
            
            while (true) {
                try (Socket socket = serverSocket.accept()) {
                    System.out.println("Cliente conectado");
                    
                    BufferedReader in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                    PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
                    
                    String mensajeCliente = in.readLine();
                    System.out.println("Mensaje del cliente: " + mensajeCliente);
                    
                    String respuestaServidor = "Hola, ¿qué tal?";
                    out.println(respuestaServidor);
                    System.out.println("Respuesta enviada al cliente: " + respuestaServidor);
                } catch (IOException e) {
                    System.out.println("Error en la conexión con el cliente: " + e.getMessage());
                }
            }
        } catch (IOException e) {
            System.out.println("Error al iniciar el servidor: " + e.getMessage());
        }
    }
}
