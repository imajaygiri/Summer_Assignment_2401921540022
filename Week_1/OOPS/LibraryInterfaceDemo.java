public class LibraryInterfaceDemo {
    public static void main(String args[]) {

        /*
         * Create an instance of KidUser class.
         * Set the age as specified in the below table and invoke the registerAccount
         * method of the
         * KidUser object
         * Age
         * 10
         * 18
         */

        LibraryUser kidUser1 = new KidUser(10, "");
        LibraryUser kidUser2 = new KidUser(18, "");

        kidUser1.registerAccount();
        kidUser2.registerAccount();

        /*
         * Set the book Type as specified in the below table and invoke the
         * requestBook
         * method of the
         * KidUser object,
         * 
         * BookType
         * “Kids”
         * “Fiction”
         */

        LibraryUser kidUser3 = new KidUser(0, "Kids");
        LibraryUser kidUser4 = new KidUser(0, "Fiction");
        kidUser3.requestBook();
        kidUser4.requestBook();

        /*
         * Test case #2:
         * Create an instance of AdultUser class.
         * Set the age as specified in the below table and invoke the registerAccount
         * method of the
         * AdultUser object
         * Age
         * 5
         * 23
         * Set the book Type as specified in the below table and invoke the requestBook
         * method of the
         * AdultUser object
         * BookType
         * “Kids”
         * “Fiction”
         */

        LibraryUser adultUser1 = new AdultUser(5);
        LibraryUser adultUser2 = new AdultUser(23);
        adultUser1.registerAccount();
        adultUser2.registerAccount();

        LibraryUser adultUser3 = new AdultUser(0, "Kids");
        LibraryUser adultUser4 = new AdultUser(0, "Fiction");
        adultUser3.requestBook();
        adultUser4.requestBook();

    }
}
