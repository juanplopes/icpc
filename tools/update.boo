import System
import System.IO
import System.Text
import System.Linq.Enumerable from System.Core

class Problem:
    [getter(Number)]
    number as string
    [getter(Title)]
    title as string
    [getter(Categories)]
    categories as string*

    def constructor(number, title, categories):
        self.number = number
        self.title = title
        self.categories = categories

    virtual def Line(prefix) as string:
        pass


class UvaProblem(Problem):
    def constructor(number, title, categories):
        super(number, title, categories)

    def Line(prefix):
        return "{0} [UVA {1} - {2}](http://uva.onlinejudge.org/external/{3}/{4}.html)" % [prefix, Number, Title, int.Parse(Number)/100, Number]

class TimusProblem(Problem):
    def constructor(number, title, categories):
        super(number, title, categories)
        
    def Line(prefix):
        return "{0} [TIMUS {1} - {2}](http://acm.timus.ru/problem.aspx?num={3})" % [prefix, Number, Title, Number]

class SpojBrProblem(Problem):
    def constructor(number, title, categories):
        super(number, title, categories)
        
    def Line(prefix):
        return "{0} [SPOJ BR {1} - {2}](http://br.spoj.pl/problems/{3})" % [prefix, Number, Title, Number]

	
def ReadProblems(dir, type as Func[of string, string, string*, Problem]) as Problem*:
    for file in Directory.GetFiles(dir, "*.cpp"):
        lines = File.ReadAllLines(file).TakeWhile({x|x.StartsWith ("//")}).Select ({x|x.Substring(2).Trim()}).ToArray();
        if lines.Length < 3:
            print "Unable to get information from problem metadata: {0}" % [file]
            continue
            
        number = lines[0]
        title = lines[1]
        categories = lines.Skip(2).SelectMany({x|@/;/.Split(x).Select({y|y.Trim()})}).ToArray();

        if categories.Length < 2:
            print "Too few categories. Expected two at least: {0}" % [file]
        
        yield type(number, title, categories)

def MaybeNumber(s as string):
    try:
        return int.Parse(s)
    except:
        return s

def WriteReadme(level as int, problems as Problem*) as string:
    sb = StringBuilder()
      
    prefix = ("#" if level == 0 else string(char(' '), (level-1)*4) + "*")
     
    if problems.Count() == 1:
        problem = problems.First()
        sb.Append(problem.Line(prefix))
        if problem.Categories.Skip(level).Any():
            sb.Append(" ({0})" % [ string.Join(", ", problem.Categories.Skip(level).ToArray()) ])
        sb.AppendLine()
    else:
        for category in problems.ToLookup({x|x.Categories.Skip(level).FirstOrDefault()}).OrderBy({x|x.Key}):
            if category.Key != null:
                sb.AppendLine("{0} **{1}**" % [prefix, category.Key])
                sb.Append(WriteReadme(level+1, category))
            else:
                for problem in category.OrderBy({x|x.Number}):
                    sb.Append(WriteReadme(level, (problem,)))
            sb.AppendLine()
    return sb.ToString()

problems = (
    ReadProblems("uva", {a,b,c|UvaProblem(a,b,c)}).Union(
    ReadProblems("timus", {a,b,c|TimusProblem(a,b,c)})).Union(
    ReadProblems("spojbr", {a,b,c|SpojBrProblem(a,b,c)}))
)
    
File.WriteAllText("README.md", WriteReadme(0, problems))		

