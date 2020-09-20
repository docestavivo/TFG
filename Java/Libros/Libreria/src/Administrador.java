
import java.io.Serializable;


public class Administrador implements Serializable{
    
    private String username="admin";
    private String password="admin";

    public Administrador() {
    }
    
    

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }
    
    
    
    
    
}
