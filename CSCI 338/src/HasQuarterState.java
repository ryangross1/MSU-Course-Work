/**
 *
 * @author yaw
 */
public class HasQuarterState implements State {

    private GumballMachine gumballMachine;

    public HasQuarterState(GumballMachine m) {
        gumballMachine = m;
    }

    @Override
    public void insertQuarter() {
        System.out.println("Already a quarter inserted");
    }

    @Override
    public void removeQuarter() {
        System.out.println("Quarter removed");
        gumballMachine.setState(gumballMachine.getNoQuarterState());
    }

    @Override
    public void turnCrank() {
        System.out.println("Gumball Delivered!");
        gumballMachine.setState(gumballMachine.getHasQuarterState());
    }
}
