require 'rubygems'
require 'redcarpet'
require 'cgi'

def markdown(text)
    options = [:hard_wrap, :filter_html, :autolink, :no_intraemphasis, :fenced_code, :gh_blockcode]
    RedcarpetCompat.new(text, *options).to_html
end

puts '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
    <html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
        <title>compiled</title>'
puts '<script type="text/javascript">'
puts File.read(File.join(File.dirname(__FILE__), 'shCore.js'))
puts '</script>'

puts '<script type="text/javascript">'
puts File.read(File.join(File.dirname(__FILE__), 'shBrushCpp.js'))
puts '</script>'

puts '<style type="text/css">'
puts File.read(File.join(File.dirname(__FILE__), 'shCoreDefault.css'))
puts '</style>'

puts '<style type="text/css">'
puts File.read(File.join(File.dirname(__FILE__), 'compiled.css'))
puts '</style>'


puts '<script type="text/javascript">SyntaxHighlighter.all();</script>
    </head>
    <body>'

puts "<style>.break { page-break-after: always;; }</style>"

puts "<div class='break'>"
puts markdown(File.read('README.md'))
puts "</div>" 

puts "<div>"
['uva', 'timus', 'spoj', 'spojbr'].each do |dir| 
    Dir.glob(File.join(dir, "*.cpp")).sort_by {|s| File.split(s)[1].split('.')[0].to_i }.each do |file|
        puts "<h1>#{file}</h1>"
        puts '<pre class="brush: cpp">'
        puts CGI::escapeHTML(File.read(file))
        puts '</pre>'
    end
end
puts "</div>" 

puts '</body></html>'

