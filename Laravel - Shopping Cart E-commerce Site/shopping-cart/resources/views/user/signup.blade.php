@extends('layouts.master')

@section('content')
<div class="row">
    <div class="">
        <h1 class="pt-5">Sign Up</h1>
        @if(count($errors) > 0)
            <div class="alert alert-danger">
                @foreach($errors->all() as $error)
                    <p>{{ $error }}</p>
                @endforeach
            </div>
        @endif
        <form action="{{ route('user.signup') }}" method="post">
            <div class="form-group pt-3">
                <label for="email">Email Address</label>
                <input type="text" id="email" name="email" placeholder="name@example.com" class="form-control" style="width: 30%">
            </div>
            <div class="form-group pt-3 pb-4">
                <label for="password">Password</label>
                <input type="password" id="password" name="password" placeholder="Min. 8 characters" class="form-control" style="width: 30%">
            </div>
            <button type="submit" class="btn btn-primary">Sign Up</button>
            {{ csrf_field() }}
        </form>
    </div>
</div>
@endsection
