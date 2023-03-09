public class Cow {
    private String name;
    private String breed;
    private int age;
    public static void main(String[] args) {
		
            System.out.println("Moo...!");
  
	}
    public void setName(String newName) {
        name = newName;
    }

    public void setBreed(String newBreed) {
        breed = newBreed;
    }

    // Set the age of the Cow to 4

    public void setAge(int newAge) {
        age = newAge;
    }
    // Call the moo() method
    
    public void moo() {
        System.out.println("Moo...!");
    }
}