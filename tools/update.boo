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
      
    prefix = ("#" if level == 0 else string(char(' '), (level-1)*4) + "*")
     
    if problems.Count() == 1:
        problem = problems.First()
        sb.Append("{0} {1} - {2}" % [prefix, problem.Number, problem.Title])
        if problem.Categories.Skip(level).Any():
            sb.Append(" ({0})" % [ string.Join(", ", problem.Categories.Skip(level).ToArray()) ])
        sb.AppendLine()
    else:
        for category in problems.ToLookup({x|x.Categories.Skip(level).FirstOrDefault()}).OrderBy({x|x.Key}):
            if category.Key != null:
                sb.AppendLine("{0} *{1}*" % [prefix, category.Key])
                sb.Append(WriteReadme(level+1, category))
            else:
                for problem in category:
                    sb.Append(WriteReadme(level, (problem,)))
            sb.AppendLine()
    return sb.ToString()
        

            
    
        
problems = ReadProblems("src")
File.WriteAllText("README.md", WriteReadme(0, problems))		

