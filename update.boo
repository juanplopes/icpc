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


def WriteReadme(level as int, problems as Problem*) as string:
    sb = StringBuilder()
        
    prefix = ('#' if level==0 else string(char(' '), (level-1)*2) + '*')
        
    if (problems.Count() > 1):
        for category in problems.ToLookup({x|x.Categories.Skip(level).First()}):
            sb.AppendLine("{0} {1}" % [prefix, category.Key])
            sb.Append(WriteReadme(level+1, category))
    else:
        problem = problems.FirstOrDefault()
        if (problem):
            sb.Append("{0} {1} - {2}" % [prefix, problem.Number, problem.Title])
    return sb.ToString()    

    
        
problems = ReadProblems(".")
File.WriteAllText("README.md", WriteReadme(0, problems))

