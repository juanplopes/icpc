import System.IO
import System.Text
import System.Linq.Enumerable from System.Core

class Problem:
    [getter(Number)]
    number as int
    [getter(Title)]
    title as string
    [getter(Categories)]
    categories as string*

    Category():
        get:
            return categories.First()
        
    SubCategory:
        get:
            return categories.Skip(1).First()
    
    Additional:
        get:
            return categories.Skip(2)
    
    def constructor(number, title, categories):
        self.number = number
        self.title = title
        self.categories = categories
	
def ReadProblems(dir):
    for file in Directory.GetFiles(dir, "*.cpp"):
        lines = File.ReadAllLines(file).TakeWhile({x|x.StartsWith ("//")}).Select ({x|x.Substring(2).Trim()}).ToArray();
        if lines.Length < 3:
            print "Unable to get information from problem metadata: {0}" % [file]
            continue
            
        number = int.Parse(lines[0])
        title = lines[1]
        categories = lines.Skip(2).SelectMany({x|@/;/.Split(x).Select({y|y.Trim()})}).ToArray();

        if categories.Length < 2:
            print "Too few categories. Expected two at least: {0}" % [file]
        
        yield Problem(number, title, categories)


def WriteReadme(problems as Problem*):
    sb = StringBuilder()
        
    for category in problems.ToLookup({x|x.Category}):
        sb.AppendLine("# {0}" % [category.Key])
        for subCategory in category.ToLookup({x|x.SubCategory}):
            sb.AppendLine("* {0}" % [subCategory.Key])
            for problem in subCategory:
                sb.Append("  * {0} - {1}" % [problem.Number, problem.Title])
                if problem.Additional.Any():
                    sb.Append(" (also: {0})" % string.Join(", ", problem.Additional.ToArray()))
                sb.AppendLine()
            
    File.WriteAllText("README.md", sb.ToString())
        
problems = ReadProblems(".")
WriteReadme(problems)		

