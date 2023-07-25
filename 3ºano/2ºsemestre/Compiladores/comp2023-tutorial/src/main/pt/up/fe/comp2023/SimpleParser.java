package pt.up.fe.comp2023;

import pt.up.fe.comp2023.JavammLexer;
import pt.up.fe.comp2023.JavammParser;
import org.antlr.v4.runtime.ANTLRInputStream;
import org.antlr.v4.runtime.CommonTokenStream;
import pt.up.fe.comp.jmm.ast.antlr.AntlrParser;
import pt.up.fe.comp.jmm.parser.JmmParser;
import pt.up.fe.comp.jmm.parser.JmmParserResult;
import pt.up.fe.comp.jmm.report.Report;
import pt.up.fe.comp.jmm.report.ReportType;
import pt.up.fe.comp.jmm.report.Stage;

import java.util.Collections;
import java.util.Map;

/**
 * Copyright 2022 SPeCS.
 * <p>
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * <p>
 * http://www.apache.org/licenses/LICENSE-2.0
 * <p>
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on
 * an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the
 * specific language governing permissions and limitations under the License. under the License.
 */

public class SimpleParser implements JmmParser {

    @Override
    public String getDefaultRule() {
        return "program";
    }

    @Override
    public JmmParserResult parse(String jmmCode, String startingRule, Map<String, String> config) {

        try {
            // Convert code string into a character stream
            var input = new ANTLRInputStream(jmmCode);
            // Transform characters into tokens using the lexer
            var lex = new JavammLexer(input);
            // Wrap lexer around a token stream
            var tokens = new CommonTokenStream(lex);
            // Transforms tokens into a parse tree
            var parser = new JavammParser(tokens);

            // Convert ANTLR CST to JmmNode AST
            return AntlrParser.parse(parser, startingRule)
                    // If there were no errors and a root node was generated, create a JmmParserResult with the node
                    .map(root -> new JmmParserResult(root, Collections.emptyList(), config))
                    // If there were errors, create an error JmmParserResult without root node
                    .orElseGet(() -> JmmParserResult.newError(new Report(ReportType.WARNING, Stage.SYNTATIC, -1,
                            "There were syntax errors during parsing, terminating")));

        } catch (Exception e) {
            // There was an uncaught exception during parsing, create an error JmmParserResult without root node
            return JmmParserResult.newError(Report.newError(Stage.SYNTATIC, -1, -1, "Exception during parsing", e));
        }
    }
}
