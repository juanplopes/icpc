require 'rubygems'
require 'redcarpet'

def markdown(text)
    options = [:hard_wrap, :filter_html, :autolink, :no_intraemphasis, :fenced_code, :gh_blockcode]
    Redcarpet.new(text, *options).to_html
end

puts "<style>.break { page-break-after: always; }</style>"

Dir.glob("**/").each do |dir|
    puts "<div class='break'>" + markdown(File.read(File.join(dir, 'README.md'))) + "</div>" 
    Dir.glob(File.join(dir, "*.cpp")).sort_by {|s| File.split(s)[1].split('.')[0].to_i }.each do |file|
        puts "<div class='break'>" + markdown("#"+file+"\n``` cpp\n" + File.read(file) + "\n ```\n") + "</div>"
    end
end

