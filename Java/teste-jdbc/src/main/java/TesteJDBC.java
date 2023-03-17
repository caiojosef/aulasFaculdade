import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class TesteJDBC {

	public static void main(String[] args) throws Exception {
		String driver = "com.mysql.jdbc.Driver";
		String url = "jdbc:mysql://localhost:3306/test";
		String usuario = "root";
		String senha = "1234";

		Class.forName(driver);
		Connection conn = DriverManager.getConnection(url, usuario, senha);
		Statement stmt = conn.createStatement();
		ResultSet results = stmt.executeQuery("select * from cotacao");
		while (results.next()) {
			System.out.println(results.getString(1) + results.getString(2));
		}
		stmt.close();
		conn.close();
	}
}