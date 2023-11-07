
import java.util.HashSet;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author yaw
 */
public class Proj3 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String testResults = "";
        int score = 0;
        // Exact VC
        testResults += "Test 1 (Exact VC): ";
        Graph graph = new Graph("test1.txt");
        int[] vertexSet = null;
        try {
            vertexSet = GraphToolBox.exactVC(graph);
        } catch (Exception e) {
            testResults += "FAIL - " + e.toString();
        }
        if (vertexSet != null) {
            boolean pass = true;
            if (vertexSet.length != 3) {
                pass = false;
                testResults += "FAIL - |VC| = " + vertexSet.length + ", not 3";
            }

            HashSet<Integer> vertexCover = new HashSet<>();
            for (int i : vertexSet) {
                vertexCover.add(i);
            }

            if (!vertexCover.contains(2)) {
                pass = false;
                testResults += "FAIL - 2 not in VC";
            }

            if (!vertexCover.contains(4)) {
                pass = false;
                testResults += "FAIL - 4 not in VC";
            }

            if (!vertexCover.contains(7)) {
                pass = false;
                testResults += "FAIL - 7 not in VC";
            }

            if (pass) {
                testResults += "PASS";
                score += 5;
            }
        }
        testResults += "\n";

        testResults += "Test 2 (Exact VC): ";
        graph = new Graph("test2.txt");
        vertexSet = null;
        try {
            vertexSet = GraphToolBox.exactVC(graph);
        } catch (Exception e) {
            testResults += "FAIL - " + e.toString();
        }
        if (vertexSet != null) {
            if (vertexSet.length != 3) {
                testResults += "FAIL - |VC| = " + vertexSet.length + ", not 3";
            } else {
                testResults += "PASS";
                score += 5;
            }
        }
        testResults += "\n";

        // Exact IS
        testResults += "\n";
        testResults += "Test 3 (Exact IS): ";
        graph = new Graph("test1.txt");
        vertexSet = null;
        try {
            vertexSet = GraphToolBox.optimalIS(graph);
        } catch (Exception e) {
            testResults += "FAIL - " + e.toString();
        }
        if (vertexSet != null) {
            boolean pass = true;
            if (vertexSet.length != 5) {
                pass = false;
                testResults += "FAIL - |IS| = " + vertexSet.length + ", not 5";
            }

            HashSet<Integer> independentSet = new HashSet<>();
            for (int i : vertexSet) {
                independentSet.add(i);
            }

            if (!independentSet.contains(0)) {
                pass = false;
                testResults += "FAIL - 0 not in VC";
            }

            if (!independentSet.contains(1)) {
                pass = false;
                testResults += "FAIL - 1 not in VC";
            }

            if (!independentSet.contains(3)) {
                pass = false;
                testResults += "FAIL - 3 not in VC";
            }

            if (!independentSet.contains(5)) {
                pass = false;
                testResults += "FAIL - 5 not in VC";
            }

            if (!independentSet.contains(6)) {
                pass = false;
                testResults += "FAIL - 6 not in VC";
            }

            if (pass) {
                testResults += "PASS";
                score += 5;
            }
        }
        testResults += "\n";

        testResults += "Test 4 (Exact IS): ";
        graph = new Graph("test2.txt");
        vertexSet = null;
        try {
            vertexSet = GraphToolBox.optimalIS(graph);
        } catch (Exception e) {
            testResults += "FAIL - " + e.toString();
        }
        if (vertexSet != null) {
            if (vertexSet.length != 1) {
                testResults += "FAIL - |IS| = " + vertexSet.length + ", not 1";
            } else {
                testResults += "PASS";
                score += 5;
            }
        }
        testResults += "\n";
        if (score == 10) {
            score = 5;
        } else if (score == 15) {
            score = 10;
        }

        // Inexact VC
        testResults += "\n";
        int inexactScore = 0;
        for (int testNum = 1; testNum < 7; testNum++) {
            testResults += "Test " + (4 + testNum) + " (Inexact VC): ";
            graph = new Graph("test" + testNum + ".txt");
            vertexSet = null;
            try {
                vertexSet = GraphToolBox.inexactVC(graph);
            } catch (Exception e) {
                testResults += "FAIL - " + e.toString();
            }
            if (vertexSet != null) {
                if (isVC(graph, vertexSet)) {
                    testResults += "PASS - " + vertexSet.length + " out of " + graph.getGraph().length;
                    inexactScore += 3;
                } else {
                    testResults += "FAIL - Not valid";
                }
            }
            testResults += "\n";
        }
        score += Math.min(inexactScore, 15);

        // Inexact IS
        testResults += "\n";
        inexactScore = 0;
        for (int testNum = 1; testNum < 7; testNum++) {
            testResults += "Test " + (10 + testNum) + " (Inexact IS): ";
            graph = new Graph("test" + testNum + ".txt");
            vertexSet = null;
            try {
                vertexSet = complement(graph, GraphToolBox.inexactIS(graph));
            } catch (Exception e) {
                testResults += "FAIL - " + e.toString();
            }
            if (vertexSet != null) {
                if (isVC(graph, vertexSet)) {
                    testResults += "PASS - " + vertexSet.length + " out of " + graph.getGraph().length;
                    inexactScore += 3;
                } else {
                    testResults += "FAIL - Not valid";
                }
            }
            testResults += "\n";
        }
        score += Math.min(inexactScore, 15);

        System.out.println("\n\nTest Results:");
        System.out.println(testResults);
        System.out.println("Code Score: " + score + "(-" + (50 - score) + ")");
    }

    private static boolean isVC(Graph g, int[] vc) {
        int[][] graph = g.getGraph();
        HashSet<Integer> vertexCover = new HashSet<>();
        for (int i : vc) {
            vertexCover.add(i);
        }

        for (int i = 0; i < graph.length; i++) {
            for (int j = 0; j < graph[i].length; j++) {
                if (!vertexCover.contains(i) && !vertexCover.contains(graph[i][j])) {
                    return false;
                }
            }
        }
        return true;
    }

    private static int[] complement(Graph g, int[] set) {
        int[][] graph = g.getGraph();
        HashSet<Integer> vertexSet = new HashSet<>();
        for (int i : set) {
            vertexSet.add(i);
        }

        int[] complement = new int[graph.length - set.length];
        int counter = 0;
        for (int i = 0; i < graph.length; i++) {
            if (!vertexSet.contains(i)) {
                complement[counter] = i;
                counter++;
            }
        }
        return complement;
    }
}
