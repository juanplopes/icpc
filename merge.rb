require 'rubygems'
require 'redcarpet'
require 'CGI'

def markdown(text)
    options = [:hard_wrap, :filter_html, :autolink, :no_intraemphasis, :fenced_code, :gh_blockcode]
    Redcarpet.new(text, *options).to_html
end

puts '<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
    <html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
        <title>compiled</title>
        <script type="text/javascript" src="_tools/shCore.js"></script>
        <script type="text/javascript" src="_tools/shBrushCpp.js"></script>
        <link type="text/css" rel="stylesheet" href="_tools/shCoreDefault.css"/>
        <script type="text/javascript">SyntaxHighlighter.all();</script>
    </head>
    <body>'

puts "<style>.break { page-break-after: always;; }</style>"

Dir.glob("**/").each do |dir|
    if File.exists?(File.join(dir, 'README.md'))
        puts "<div class='break'>"
        puts markdown(File.read(File.join(dir, 'README.md')))
        puts "</div>" 
        puts "<div class='break'>"
        Dir.glob(File.join(dir, "*.cpp")).sort_by {|s| File.split(s)[1].split('.')[0].to_i }.each do |file|
            puts "<h1>#{file}</h1>"
            puts '<pre class="brush: cpp">'
            puts CGI::escapeHTML(File.read(file))
            puts '</pre>'
        end
        puts "</div>" 
    end
end

puts '</body></html>'

