package br.edu.uniara.mpn2.livro;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class LivroDAO {
    
    private static final String driver = "com.mysql.jdbc.Driver";
    private static final String url = "jdbc:mysql://localhost:3306/teste";
    private static final String usuario = "root";
    private static final String senha = "1234";
    
    private Connection getConnection() throws Exception {
        Class.forName(driver);
        Connection conn = DriverManager.getConnection(url, usuario, senha);
        return conn;
    }

    public void insert(LivroTO livro) throws Exception {
        
        Connection conn = getConnection();
        Statement stmt = conn.createStatement();
        
        String comando = "INSERT INTO livro (autor, titulo)" +
        "VALUES ('" + livro.getAutor() + "', '" + livro.getTitulo() + "')";
        
        stmt.executeQuery(comando);
        stmt.close();
        conn.close();

    }
}