package pt.up.fe.comp2023;

import pt.up.fe.comp.jmm.ast.AJmmVisitor;
import pt.up.fe.comp.jmm.ast.JmmNode;

public class JavaCalcGenerator extends AJmmVisitor<String, String> {
    private String className;

    public JavaCalcGenerator(String className) {
        this.className = className;
    }

    protected void buildVisitor() {
        addVisit("Program", this::dealWithProgram);
        addVisit("Assignment", this::dealWithAssignment);
        addVisit("Integer", this::dealWithLiteral);
        addVisit("Identifier", this::dealWithLiteral);
        // add here other rules !
        addVisit("ExprStmt", this::dealWithDefault);
        addVisit("BinaryOp", this::dealWithBinaryOp);
        addVisit("Parenthesis", this::dealWithParenthesis);

    }

    private String dealWithProgram(JmmNode jmmNode, String s) {
        s = (s!=null?s:"");
        String ret = s+"public class "+this.className+" {\n";
        String s2 = s+"\t";
        ret += s2+"public static void main(String[] args) {\n";

        for(JmmNode child : jmmNode.getChildren()){
            ret += visit(child,s2 + "\t");
            ret += "\n";
        }
        ret += s2 + "}\n";
        ret += s + "}\n";
        return ret;
    }

    private String dealWithAssignment(JmmNode jmmNode, String s) {
        return s+"int "+ jmmNode.get("var")
                + " = "+ visit(jmmNode.getChildren().get(0), "")
                +";";

        /*
        String ret = "";

        for (JmmNode child : jmmNode.getChildren()) {
            ret += visit(child, "");
        }

        return s + "int " + jmmNode.get("var")
                + " = " + ret
                + ";";
        */
    }

    private String dealWithLiteral(JmmNode jmmNode, String s) {
        return s+jmmNode.get("value");
    }

    private String dealWithBinaryOp(JmmNode jmmNode, String s) {
        return s+ visit(jmmNode.getChildren().get(0), "")
                + " " + jmmNode.get("op").replace("'", "") + " "
                + visit(jmmNode.getChildren().get(1), "");

        /*
        String ret = s;
        JmmNode lastChild = jmmNode.getChildren().get(jmmNode.getChildren().size() - 1);

        for(JmmNode child : jmmNode.getChildren()){
            ret += visit(child,"");
            if (child != lastChild) {
                ret += " ";
                ret += jmmNode.get("op").replace("'", "");
                ret += " ";
            }
        }

        return ret;
        */
    }

    private String dealWithDefault(JmmNode jmmNode, String s) {

        return s+ "System.out.println(" + visit(jmmNode.getChildren().get(0), "") + ");";

        /*
        String ret = s+"System.out.println(";

        for(JmmNode child : jmmNode.getChildren()){
            ret += visit(child,"");
        }
        ret += ");";

        return ret;
        */
    }

    private String dealWithParenthesis(JmmNode jmmNode, String s) {
        return "(" + visit(jmmNode.getChildren().get(0), "") + ")";

        /*
        String ret = s+"(";

        for(JmmNode child : jmmNode.getChildren()){
            ret += visit(child,"");
        }
        ret += ")";

        return ret;
        */
    }
}
