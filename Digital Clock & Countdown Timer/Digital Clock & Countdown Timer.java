import java.util.Scanner;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class Codechef 
{    
    // Function to handle the user choice
    public static void userChoice(int choice) 
    {
        if (choice == 1) 
        {
            digitalClock();
        } 
        
        else if (choice == 2) 
        {
            Scanner scanner = new Scanner(System.in);
            System.out.print("Enter the number of seconds to countdown: ");
            int seconds = scanner.nextInt();
            countdownTimer(seconds);
        } 
        
        else 
        {
            System.out.println("Invalid choice!");
        }
    }

    // Function to display the digital clock
    public static void digitalClock() 
    {
        // Infinite loop to display time
        while (true) 
        {
            // Get current time in HH:MM:SS format
            LocalTime currentTime = LocalTime.now();
            System.out.print("\rCurrent Time: " + currentTime.toString());
          
            try
            {
                // Pause for 1 second
                Thread.sleep(1000);
            } 
            
            catch (InterruptedException e) 
            {
                System.out.println("Error: " + e.getMessage());
            }
        }
    }

    // Function to handle countdown timer
    public static void countdownTimer(int seconds) 
    {
        System.out.println("Countdown Timer started!");
      
        while (seconds > 0) 
        {
            System.out.print("\rTime remaining: " + seconds + " seconds");
          
            try 
            {
                // Pause for 1 second
                Thread.sleep(1000);
            } 
            
            catch (InterruptedException e) 
            {
                System.out.println("Error: " + e.getMessage());
            }
          
            seconds--;
        }
      
        System.out.println("\nTime's up!");
    }

    // Main method for user input and program control
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
      
        while (true) 
        {
            System.out.print("Choose an option (1: Digital Clock, 2: Countdown Timer): ");
            int choice = scanner.nextInt();
            userChoice(choice);
        }
    }
}
