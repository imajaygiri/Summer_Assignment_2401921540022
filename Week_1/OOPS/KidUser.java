
public class KidUser implements LibraryUser {
    public int age;
    public String bookType;

    KidUser(int age) {
        this.age = age;
        this.bookType = "";
    }

    KidUser(int age, String bookType) {
        this.age = age;
        this.bookType = bookType;
    }

    @Override
    public void registerAccount() {
        if (this.age < 12) {
            System.out.println(
                    "You have successfully registered under a Kids Account");
        } else if (this.age > 12) {
            System.out.println(
                    "Sorry, Age must be less than 12 to register as a kid");
        }

    }

    @Override
    public void requestBook() {

        if (this.bookType == "") {
            return;
        }

        if (this.bookType == "Kids") {
            System.out.println(
                    "Book Issued successfully, please return the book within 10days");
        } else {
            System.out.println("Oops, you are allowed to take only kids books");
        }

    }

}
