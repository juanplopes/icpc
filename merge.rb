require 'rubygems'
require 'redcarpet'

def markdown(text)
    options = [:hard_wrap, :filter_html, :autolink, :no_intraemphasis, :fenced_code, :gh_blockcode]
    Redcarpet.new(text, *options).to_html
end

puts "<style>div.break { page-break-before: always; }</style>"

Dir.glob("**/").each do |dir|
    puts markdown(File.read(File.join(dir, 'README.md'))) 
    puts "<div class='break'>&nbsp;</div>"
    Dir.glob(File.join(dir, "*.cpp")).sort_by {|s| File.split(s)[1].split('.')[0].to_i }.each do |file|
        puts markdown("#"+file+"\n``` cpp\n" + File.read(file) + "\n ```\n")
        puts "<div class='break'>&nbsp;</div>"
    end
end

