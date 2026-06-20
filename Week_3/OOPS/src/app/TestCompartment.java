import compartment.Compartment;
import compartmentTypes.FirstClass;
import compartmentTypes.General;
import compartmentTypes.Ladies;
import compartmentTypes.Luggage;

import java.util.concurrent.ThreadLocalRandom;

public class TestCompartment {
    @FunctionalInterface
    private interface CompartmentFactory {
        Compartment create();
    }

    public static void main(String[] args) {
        Compartment[] compartments = new Compartment[10];
        CompartmentFactory[] factories = {
                FirstClass::new,
                Ladies::new,
                General::new,
                Luggage::new
        };

        for (int i = 0; i < compartments.length; i++) {
            int randomNumber = ThreadLocalRandom.current().nextInt(1, 5);
            compartments[i] = factories[randomNumber - 1].create();
        }

        for (int i = 0; i < compartments.length; i++) {
            System.out.printf(
                    "Compartment %d (%s): %s%n",
                    i + 1,
                    compartments[i].getClass().getSimpleName(),
                    compartments[i].notice()
            );
        }
    }
}
